#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>//Para cargar imagenes
#include <allegro5/allegro_font.h>//addon fuente
#include <allegro5/allegro_ttf.h>//TrueTypefonts
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>//para desplegar mensajes
#include <iostream>//Para operaciones como el debug o el cout




int main() {
    if (!al_init()) {
        std::cerr << "Error inicializando Allegro!\n";
        return -1;
    }

    ALLEGRO_DISPLAY* display = al_create_display(800, 600);
    if (!display) {
        std::cerr << "Error creando el display!\n";
        return -1;
    }

    al_set_window_position(display, 100, 50);//Establece la posición del display
    al_set_window_title(display, "Práctica de Allegro");//Coloca el titulo


	al_init_image_addon();//Inicializa el addon de imagenes
	ALLEGRO_BITMAP* player = al_load_bitmap("assets/link.JPG");//Le asigna a player la imagen link.JPG
	int w = al_get_bitmap_width(player);//Obtiene el ancho de la imagen
	int h = al_get_bitmap_height(player);//Obtiene la altura de la imagen

    float player_x = 0; // esquina inferior izquierda
    float player_y = al_get_display_height(display) - h;
    float vx = 0, vy = 0;
    ALLEGRO_BITMAP* ganon = al_load_bitmap("assets/ganon.JPG");
    float ganon_x = 400;
    float ganon_y = 300;
    float ganon_vx = 2; // velocidad horizontal
    float ganon_vy = 0;

    al_draw_bitmap(player, player_x, player_y, 0);
   


	al_init_font_addon();//Para controlar fuentes.
    al_init_ttf_addon(); // para TTF.

    ALLEGRO_FONT* fuente = al_load_ttf_font("assets/BAUHS93.ttf", 24, 0);//Asigna una fuente para el programa.
    if (!fuente) {
        std::cerr << "Error: no se pudo cargar la fuente assets/BAUHS93.ttf" << std::endl;
        return -1;
    }
	al_draw_text(fuente, al_map_rgb(255, 255, 255), 400, 20, ALLEGRO_ALIGN_CENTER, "Practica de Allegro");//Dibuja el texto en la pantalla.
    al_flip_display();
    al_install_keyboard();//Para manipular con el teclado
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);//Define un timer a 60 fps
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();//Define la cola de eventos.
    al_register_event_source(queue, al_get_keyboard_event_source()); 
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_display_event_source(display));



    ALLEGRO_EVENT ev;
    bool running = true;
    al_start_timer(timer);
    while (running) {
        al_wait_for_event(queue, &ev);
        if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:    vy = -4; break;
            case ALLEGRO_KEY_DOWN:  vy = 4; break;
            case ALLEGRO_KEY_LEFT:  vx = -4; break;
            case ALLEGRO_KEY_RIGHT: vx = 4; break;
            case ALLEGRO_KEY_ESCAPE: running = false; break;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch (ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
            case ALLEGRO_KEY_DOWN:  vy = 0; break;
            case ALLEGRO_KEY_LEFT:
            case ALLEGRO_KEY_RIGHT: vx = 0; break;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_TIMER) {
            // actualizar posiciones
            player_x += vx;
            player_y += vy;
            ganon_x += ganon_vx;
            ganon_y += ganon_vy;

            if (ganon_x < 0 || ganon_x + al_get_bitmap_width(ganon) > al_get_display_width(display)) {
                ganon_vx = -ganon_vx;
            }
            if (ganon_y < 0 || ganon_y + al_get_bitmap_height(ganon) > al_get_display_height(display)) {
                ganon_vy = -ganon_vy;
            }


            // dibujar
            al_clear_to_color(al_map_rgb(0, 0, 0)); // fondo negro
            al_draw_bitmap(player, player_x, player_y, 0); // héroe
            al_draw_bitmap(ganon, ganon_x,ganon_y, 0);

            al_draw_text(fuente, al_map_rgb(255, 255, 255),
                al_get_display_width(display) / 2, 10,
                ALLEGRO_ALIGN_CENTER, "Practica de Allegro");
            al_flip_display();
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }
    }
    al_destroy_bitmap(player);
    al_destroy_bitmap(ganon);
    al_destroy_font(fuente);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    al_destroy_display(display);

return 0;
}