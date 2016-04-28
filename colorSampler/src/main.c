// freeman.justin@gmail.com

#include "colorsampler.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc,char **argv)
{
    e	*E;
    int i,j;
    int index;
    int r,g,b;
    int border;
    char  fname[200];


	// malloc the work struct
	E = malloc(sizeof(e));
	if(E==NULL) fail("malloc failed\n");

  // image dimensions
  E->width = 420;
  E->height = 420;

  // allocate memory for the image data
  if ((E->image = (char *) malloc(E->height*E->width*3*sizeof(char)) ) == NULL) {
      fail("failed to allocate memory for image \n");
  }


  // accessing 3d array as 1d
  // int* array = new int[ width * height * depth ];
  // array[ x * height * depth + y * depth + z ] = value;

  // background fill
  for (j=0;j<E->height;j++) {
      for (i=0;i<E->width;i++) {
          for(index=0;index<3;index++) {
              E->image[j * E->height * 3 + i * 3 + index] = 240;
          }
      }
  }


  // loop through the rgb space
  // create the image (420x420 with a 35 pixel border)
  border = 35;

  for(r=0;r<256;r+=30){
    for(g=0;g<256;g+=30){
      for(b=0;b<256;b+=30){
        for(j=border;j<E->width-border;j++){
            for(i=border;i<E->height-border;i++){
                  E->image[j * E->height * 3 + i * 3 + 0] = r;
                  E->image[j * E->height * 3 + i * 3 + 1] = g;
                  E->image[j * E->height * 3 + i * 3 + 2] = b;
            }
        }
        // write the image
        sprintf(fname,"%03d%03d%03d.png",r,g,b);
        stbi_write_png(fname, E->width, E->height, 3, (const void *)E->image, 0);

      }
    }
  }

  return 0;
}
