#ifndef __FERI
#include "Cube_drawer.hpp"
#include "texture_functions.hpp"

Cube_drawer::Cube_drawer() {
  script.push_back(std::make_pair(3, 0)); // green
  script.push_back(std::make_pair(0, 0)); // red
  script.push_back(std::make_pair(-3, 0)); // blue
  script.push_back(std::make_pair(-6, 0)); //orange
  script.push_back(std::make_pair(3, 3)); // white
  script.push_back(std::make_pair(3, -3)); // yellow

  this->scale_x = 1;
  this->scale_y = 1;
  this->scale_z = 1;
}

Cube_drawer::~Cube_drawer() {
  for (std::vector<GLuint>::iterator it = textures.begin(); it != textures.end(); ++it) {
    texture_deinit(textures[*it]);
  }
}

void Cube_drawer::load_texture(char* file_name) {
  GLuint temp_texture;
  textures.push_back(temp_texture);
  texture_init(textures[textures.size() - 1], file_name);
}

void Cube_drawer::draw_square() {
  glColor3ub(0, 153, 76);
  glBegin(GL_QUAD_STRIP);
  glVertex3d(scale_x * (0), scale_y * (0), scale_z * (0)); /// 0,0
  glVertex3d(scale_x * (0), scale_y * (0), scale_z * (1)); /// 0,1
  glVertex3d(scale_x * (1), scale_y * (0), scale_z * (0)); /// 1,0
  glVertex3d(scale_x * (1), scale_y * (0), scale_z * (1)); /// 1,1
  glEnd();
}

void Cube_drawer::draw_flattened_cube(std::vector<int> &colors) {
  int size = 3;
  int shift = size / 2;
  int index = 0;
  for (int i = 0; i < 6; i++) {
    for (int x = 0 - shift - script[i].first; x < size - shift - script[i].first; x++) {
      for (int z = 0 - shift - script[i].second; z < size - shift - script[i].second; z++) {
        texture_blind_and_enable(textures[colors[index]]);
        glBegin(GL_POLYGON);

        glTexCoord2i(0, 0);
        glVertex3f(float(x), 0, float(z));
        glTexCoord2i(1, 0);
        glVertex3f((float(x) + 1), 0, float(z));
        glTexCoord2i(1, 1);
        glVertex3f((float(x) + 1), 0, (float(z) + 1));
        glTexCoord2i(0, 1);
        glVertex3f(float(x), 0, (float(z) + 1));

        glEnd();
        texture_disable();
        index++;
      }
    }
  }
}

void Cube_drawer::draw_real_cube(std::vector<int>& colors) {
  int size = 3;
  int shift = size / 2;
  int index = 0;
  int y = 0;
  for (int i = 0; i < 6; i++) {
    for (int x = 0 - shift - script[i].first; x < size - shift - script[i].first; x++) {
      for (int z = 0 - shift - script[i].second; z < size - shift - script[i].second; z++) {
        texture_blind_and_enable(textures[colors[index]]);
        glBegin(GL_POLYGON);

        glTexCoord2i(0, 0);
        glVertex3f(float(x), y, float(z));
        glTexCoord2i(1, 0);
        glVertex3f((float(x) + 1), y, float(z));
        glTexCoord2i(1, 1);
        glVertex3f((float(x) + 1), y, (float(z) + 1));
        glTexCoord2i(0, 1);
        glVertex3f(float(x), y, (float(z) + 1));

        glEnd();
        texture_disable();
        index++;
      }
    }
  }
}


#endif
