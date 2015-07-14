#include <pebble.h>
/*this is an example of how variables work in C.  For now, ignore all of the set up code for the app, and we are just going to focus on a small bit of
code that focuses on how you can store information in variables.*/
  
  
  
Window *my_window;
TextLayer *text_layer;

static void main_window_load(Window *window){
  //Here is where we are going to work for this project---------------------------------------
//Loops are super important, they allow us to reuse blocks of code without having to write out all of
//the instructions again.  There are three types of loops that we are going to go over right now.
//They all work for different situations, but for now, just use whatever loop makes the most sense to you, and your team.

//First thing is first, let's create a variable to hold the words that we want to put on the screen
// a.k.a. a "string"
  static char output_string[1000] = "HELLO! ";
//in this case we are specifying the maximum number of characters in the string, 1000  
  
  
//We are going to need some way to determine what the coditions for running the loop again are.  
//usually this is done by using a variable to store an integer and then using that to keep track of
//how many times the loop has happened.
  int loop_counter = 0;
  

  //WHILE LOOP----------------------------------------------------------------------------------------------
//this is a while loop.  It will only run if the loop_counter variable is less than 3, and since we just 
//assigned it the value of 0, this loop will run
while(loop_counter < 3){

  //if you haven't seen strcat(), before, just know that it stitches together text look it up on pebble dev documentation for more info.
  strcat(output_string, "hello again, ");

  loop_counter = loop_counter + 1;
}
 

//DO WHILE LOOP---------------------------------------------------------------------------------------------
//this is the do, while loop.  It will always run once, but will run more times if the condition defined after it is true.
  do{
    strcat(output_string, " and one last time");
  }
  while(loop_counter < 3);


  
//FOR LOOP-------------------------------------------------------------------------------------------------- 
//this is the for loop.  It is a good multipurpose loop that allows for a great deal of flexiblity.
//One handy thing about a for loop is that you create your own little counter variable that doesn't affect the rest of your code.
//It does a couple of things right away.  It defines it's own counter; sets the condition; then advances the counter all in one little
//compact package.  Notice that we aren't using the "loop_counter" at all in this compact little bit of code.
  for(int i = 0; i < 4; i++){
    strcat(output_string, "! ");
  }

  
  
  
  
  //start playing with the code above and see if you can change the message, and the number of times that the message appears.
 

 //------------------------------------------------------------------------------------------
  
  Layer *window_layer = window_get_root_layer(window);
  text_layer = text_layer_create(GRect(0, 0, 144, 60));
  
//-------------------------------------------------------------------------------------------
  text_layer_set_text(text_layer, output_string );
//-------------------------------------------------------------------------------------------
  
  text_layer_set_text_color(text_layer, GColorBlack);
  
  layer_add_child(window_layer, text_layer_get_layer(text_layer));

}

static void main_window_unload(){
   text_layer_destroy(text_layer);
}

void handle_init(void) {
  my_window = window_create();
 
  
  window_set_window_handlers(my_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  
  window_stack_push(my_window, true);
}

void handle_deinit(void) {
 window_destroy(my_window);
}


int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}
