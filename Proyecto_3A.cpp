// Proyecto_3A
/*Integrantes:
-Daniel Alejandro Arrieta Víquez
-Ronny Espinoza Cordero
-Cristhofer Herrera
*/

#define _CRT_SECURE_NO_WARNINGS // Se usa para evitar advertencias de funciones "inseguras"
#include <cstdio>       // Manejo de archivos en C
#include <fstream>      // Manejo de archivos en C++
#include <iostream>     // Entrada y salida estándar
#include <map>          // Mapa ordenado
#include <unordered_map>// Mapa no ordenado
#include <vector>       // Vectores dinámicos
#include <algorithm>    // Funciones de ordenamiento
#include <chrono>       // Medición de tiempo
#include <stdio.h>      // Entrada/salida estándar
#define ll unsigned long long int // Tipo para frecuencias grande

// Espacio de nombres Huffman: agrupa todas las funciones y estructuras
namespace Huffman {

    // Arreglo global que guarda el código Huffman de cada carácter
    std::string HuffmanValue[256] = { "" };

    // Estructura de nodo para el árbol Huffman
    struct Node {
        char character; // Carácter representado
        ll count; // Frecuencia del carácter
        Node* left, * right; // Hijos izquierdos y derechos

        // Constructor para nodo interno (solo frecuencia)
        Node(ll count) {
            this->character = 0;
            this->count = count;
            this->left = this->right = nullptr;
        }

        // Constructor para nodo hoja (carácter + frecuencia)
        Node(char character, ll count) {
            this->character = character;
            this->count = count;
            this->left = this->right = nullptr;
        }
    };

    // Utilidades comunes
    namespace Utility {
        // Obtiene el tamaño de un archivo en bytes
        ll get_file_size(const char* filename) {
            FILE* p_file = fopen(filename, "rb");
            fseek(p_file, 0, SEEK_END);
            ll size = ftell(p_file);
            fclose(p_file);
            return size;
        }

        // Recorre el árbol en orden e imprime códigos Huffman
        void Inorder(Node* root, std::string& value) {
            if (root) {
                value.push_back('0');
                Inorder(root->left, value);
                value.pop_back();

                if (root->left == nullptr && root->right == nullptr) {
                    printf("Character: %c, Count: %lld, ", root->character, root->count);
                    std::cout << "Huffman Value: " << value << std::endl;
                }

                value.push_back('1');
                Inorder(root->right, value);
                value.pop_back();
            }
        }
    };

    // Recorre el árbol en orden e imprime códigos Huffman
    namespace CompressUtility {

        // Combina dos nodos en uno nuevo (suma frecuencias y asigna hijos)
        Node* combine(Node* a, Node* b) {
            Node* parent = new Node((a ? a->count : 0) + (b ? b->count : 0));
            parent->left = b;
            parent->right = a;
            return parent;
        }

        // Función de comparación para ordenar nodos por frecuencia
        bool sortbysec(const Node* a, const Node* b) {
            return (a->count > b->count);
        }

        // Analiza archivo y cuenta frecuencia de cada carácter
        std::map<char, ll>parse_file(const char* filename, const ll Filesize) {
            FILE* ptr = fopen(filename, "rb");
            if (ptr == NULL) {
                perror("Error: Archivo no encontrado:");
                exit(-1);
            }
            unsigned char ch;
            ll size = 0, filesize = Filesize;
            std::vector<ll>Store(256, 0);

            // Recorre archivo y cuenta ocurrencias de cada byte
            while (size != filesize) {
                ch = fgetc(ptr);
                ++Store[ch];
                ++size;
            }

            std::map<char, ll>store;
            for (int i = 0; i < 256; ++i) {
                if (Store[i]) {
                    store[i] = Store[i];
                }
            }
            fclose(ptr);
            return store;
        }

        // Ordena nodos por frecuencia
        std::vector<Node*>sort_by_character_count(const std::map<char, ll>& value) {
            std::vector<Node*> store;
            for (auto& x : value) {
                store.push_back(new Node(x.first, x.second));
            }
            sort(store.begin(), store.end(), sortbysec);
            return store;
        }

        // Genera header con códigos Huffman y padding
        std::string generate_header(const char padding) {
            std::string header = "";
            // UniqueCharacter start from -1 {0 means 1, 1 means 2, to conserve memory}
            unsigned char UniqueCharacter = 255;

            for (int i = 0; i < 256; ++i) {
                if (HuffmanValue[i].size()) {
                    header.push_back(i); // carácter
                    header.push_back(HuffmanValue[i].size()); // longitud del código
                    header += HuffmanValue[i]; // código Huffman
                    ++UniqueCharacter;
                }
            }
            char value = UniqueCharacter;
            return value + header + (char)padding;
        }

        // Almacena códigos Huffman en arreglo global y calcula tamaño comprimido
        ll store_huffman_value(const Node* root, std::string& value) {
            ll temp = 0;
            if (root) {
                value.push_back('0');
                temp = store_huffman_value(root->left, value);
                value.pop_back();
                if (!root->left && !root->right) {
                    HuffmanValue[(unsigned char)root->character] = value;
                    temp += value.size() * root->count;
                }
                value.push_back('1');
                temp += store_huffman_value(root->right, value);
                value.pop_back();
            }
            return temp;
        }

        // Genera árbol Huffman a partir de frecuencias
        Node* generate_huffman_tree(const std::map <char, ll>& value) {
            std::vector<Node*> store = sort_by_character_count(value);
            Node* one, * two, * parent;
            sort(begin(store), end(store), sortbysec);
            if (store.size() == 1) {
                return combine(store.back(), nullptr);
            }
            while (store.size() > 2) {
                one = *(store.end() - 1); two = *(store.end() - 2);
                parent = combine(one, two);
                store.pop_back(); store.pop_back();
                store.push_back(parent);

                std::vector<Node*>::iterator it1 = store.end() - 2;
                while ((*it1)->count < parent->count && it1 != begin(store)) {
                    --it1;
                }
                std::sort(it1, store.end(), sortbysec);
            }
            one = *(store.end() - 1); two = *(store.end() - 2);
            return combine(one, two);
        }

        // Función principal de compresión
        void compress(const char* filename, const ll Filesize, const ll PredictedFileSize) {
            // Calcula padding (bits sobrantes para completar último byte)
            const char padding = (8 - ((PredictedFileSize) & (7))) & (7);
            const std::string header = generate_header(padding);
            size_t header_i = 0;
            size_t h_length = header.size();

            std::cout << "Padding size: " << (int)padding << std::endl;
            FILE* iptr = fopen(filename, "rb"), * optr = fopen((std::string(filename) + ".abiz").c_str(), "wb");
            bool write_remaining = true;

            if (!iptr) {
                perror("Error: Archivo no encontrado: ");
                exit(-1);
            }

            // Escribe header en archivo comprimido
            while (header_i < h_length) {
                fputc(header[header_i], optr);
                ++header_i;
            }

            unsigned char ch, fch = 0;
            char counter = 7;
            ll size = 0, i;
            while (size != Filesize) {
                ch = fgetc(iptr);
                i = 0;
                const std::string& huffmanStr = HuffmanValue[ch];
                while (huffmanStr[i] != '\0') {
                    write_remaining = true;
                    // OR y desplazamiento: empaqueta bit en posición correcta
                    fch = fch | ((huffmanStr[i] - '0') << counter);
                    // Decrece de 7 a 0, y luego regresa a 7
                    counter = (counter + 7) & 7;
                    // Si quedaron bits sin escribir, se guardan
                    if (counter == 7) {
                        write_remaining = false;
                        fputc(fch, optr);
                        fch ^= fch;
                    }
                    ++i;
                }
                ++size;
                if ((size * 100 / Filesize) > ((size - 1) * 100 / Filesize)) {
                    printf("\r%lld%% completedo  ", (size * 100 / Filesize));
                }
            }
            if (write_remaining) {
                fputc(fch, optr);
            }
            printf("\n");
            fclose(iptr);
            fclose(optr);
        }

    };

    // Funciones necesarias para descompresión
    namespace DecompressUtility {
        
        // Reconstruye árbol Huffman desde un código y un carácter
        void generate_huffman_tree(Node* const root, const std::string& codes, const unsigned char ch) {
            Node* traverse = root;
            int i = 0;
            while (codes[i] != '\0') {
                if (codes[i] == '0') {
                    if (!traverse->left) {
                        traverse->left = new Node(0);
                    }
                    traverse = traverse->left;
                }
                else {
                    if (!traverse->right) {
                        traverse->right = new Node(0);
                    }
                    traverse = traverse->right;
                }
                ++i;
            }
            traverse->character = ch; // asigna carácter en hoja
        }

        // Decodifica header y reconstruye árbol Huffman
        std::pair<Node*, std::pair<unsigned char, int>>decode_header(FILE* iptr) {
            Node* root = new Node(0);
            int charactercount, buffer, total_length = 1;
            char ch, len;
            charactercount = fgetc(iptr); // número de caracteres únicos -1
            std::string codes;
            ++charactercount;
            while (charactercount) {
                // carácter y longitud del código
                ch = fgetc(iptr);
                codes = "";
                len = fgetc(iptr);
                buffer = len;

                // lee el código Huffman desde el header
                while (buffer > codes.size()) {
                    codes.push_back(fgetc(iptr));
                }             
                total_length += codes.size() + 2;

                generate_huffman_tree(root, codes, ch);
                --charactercount;
            }
            unsigned char padding = fgetc(iptr); // bits de relleno
            ++total_length;
            return { root, {padding, total_length} };
        }

        // Función principal de descompresión
        void decompress(const char* filename, const ll Filesize, const ll leftover) {
            const std::string fl = filename;
            FILE* iptr = fopen(fl.c_str(), "rb"); // archivo comprimido
            FILE* optr = fopen(std::string("output" + fl.substr(0, fl.size() - 5)).c_str(), "wb"); // archivo restaurado

            if (iptr == NULL) {
                perror("Error: Archivo no encontrado");
                exit(-1);
            }

            // reconstruye árbol desde header
            std::pair<Node*, std::pair<unsigned char, int>>HeaderMetadata = decode_header(iptr);
            Node* const root = HeaderMetadata.first;
            const unsigned char padding = HeaderMetadata.second.first;
            const int headersize = HeaderMetadata.second.second;

            char ch, counter = 7;
            ll size = 0;
            const ll filesize = Filesize - headersize;
            Node* traverse = root;
            ch = fgetc(iptr);
            while (size != filesize) {
                while (counter >= 0) {
                    if (traverse == nullptr) {
                        std::cerr << "Error: nodo nulo durante la descompresión\n";
                        break;
                    }
                    // usa AND (&) para verificar bit en posición "counter"
                    traverse = ch & (1 << counter) ? traverse->right : traverse->left;
                    ch ^= (1 << counter); // limpia bit ya leído
                    --counter;
                    // si se llega a hoja, se escribe carácter original
                    if (!traverse->left && !traverse->right) {
                        fputc(traverse->character, optr);
                        if (size == filesize - 1 && padding == counter + 1) {
                            break;
                        }
                        traverse = root; // reinicia recorrido
                    }
                }
                ++size;
                counter = 7;
                if ((size * 100 / filesize) > ((size - 1) * 100 / filesize)) {
                    printf("\r%lld%% completedo, tamaño: %lld bytes   ", (size * 100 / filesize), size);
                }
                ch = fgetc(iptr);
            }
            fclose(iptr);
            fclose(optr);
        }

    } 

};

using namespace Huffman; // Usar directamente las funciones del namespace

int main(int argc, char* argv[]) {
    // Validación de argumentos: se esperan 2 parámetros (-c o -dc y el archivo)
    if (argc != 3) {
        printf("Uso:\n (a.exe|./a.out) (-c ArchivoAComprimir | -dc ArchivoADescomprimir)\n");
        exit(-1);
    }
    const char* option = argv[1], * filename = argv[2]; // opción (-c o -dc) y nombre del archivo
    printf("%s\n", filename);

    // Variables para medir tiempo de ejecución
    std::chrono::time_point <std::chrono::system_clock> start, end;
    std::chrono::duration <double> time;
    ll filesize = 0, predfilesize = 0;;
    // Opción de compresión
    if (std::string(option) == "-c") {
        filesize = Utility::get_file_size(filename); // obtiene tamaño original
        auto mapper = CompressUtility::parse_file(filename, filesize); // cuenta frecuencias
        Node* const root = CompressUtility::generate_huffman_tree(mapper); // genera árbol
        std::string buf = "";
        predfilesize = CompressUtility::store_huffman_value(root, buf); // calcula tamaño comprimido
        printf("Archivo original: %lld bytes\n", filesize);
        printf("Tamaño comprimido (sin header): %lld bytes\n", (predfilesize + 7) >> 3);

        start = std::chrono::system_clock::now();
        CompressUtility::compress(filename, filesize, predfilesize); // comprime archivo
        end = std::chrono::system_clock::now();

        time = (end - start);
        std::cout << "Tiempo de compresión: " << time.count() << "s" << std::endl;

    }
    // Opción de descompresión
    else if (std::string(option) == "-dc") {
        filesize = Utility::get_file_size(filename); // tamaño del archivo comprimido
        start = std::chrono::system_clock::now();
        DecompressUtility::decompress(filename, filesize, predfilesize); // descomprime archivo
        end = std::chrono::system_clock::now();

        time = (end - start);
        std::cout << "\nTiempo de descompresión: " << time.count() << "s" << std::endl;
    }
    // Opción inválida
    else {
        std::cout << "\nOpción inválida... Saliendo\n";
    }
    return 0; // Fin del programa
}
