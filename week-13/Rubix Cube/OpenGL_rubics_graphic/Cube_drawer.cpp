#include "Cube_drawer.hpp"
#include "texture_functions.hpp"

Cube_drawer::Cube_drawer() {
  cooord.push_back(std::make_pair(std::make_pair(0, 0), 0));
  cooord.push_back(std::make_pair(std::make_pair(-1, 0), 1));
  cooord.push_back(std::make_pair(std::make_pair(1, -3), 0));
  cooord.push_back(std::make_pair(std::make_pair(2, 2), 0));
  cooord.push_back(std::make_pair(std::make_pair(0, -1), 2));
  cooord.push_back(std::make_pair(std::make_pair(0, -2), -1));

  script.push_back(std::make_pair(0, 3)); // green
  script.push_back(std::make_pair(0, 0)); // red
  script.push_back(std::make_pair(0, -3)); // blue
  script.push_back(std::make_pair(0, -6)); //orange
  script.push_back(std::make_pair(3, 3)); // white
  script.push_back(std::make_pair(-3, 3)); // yellow

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

void Cube_drawer::draw_flattened_cube(std::vector<int> &colors, int rubic_size) {
  int i = 0;
  int shift = 0;
  int index = 0;
  for (int i = 0; i < 6; i++) {
    for (int z = 0 - shift - script[i].first; z < rubic_size - shift - script[i].first; z++) {
      for (int x = 0 - shift - script[i].second; x < rubic_size - shift - script[i].second; x++) {
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

void Cube_drawer::draw_real_cube(std::vector<int>& colors, int rubic_size) {
  int arr_counter = 0;
  rubic_size = 3;
  int index = 0;
  int i = 0;
  int middle_point = rubic_size / 2;

  int shift_x = middle_point * 0;
  int shift_z = middle_point * 0;
  int shift_y = middle_point * 0;

  //for (int i = 0; i < 6; i++) {
    for (int z = 0 - shift_z - middle_point; z < rubic_size - shift_z - middle_point; z++) {
      for (int x = 0 - shift_x - middle_point; x < rubic_size - shift_x - middle_point; x++) {
        texture_blind_and_enable(textures[colors[index]]);
        glBegin(GL_POLYGON);

        glTexCoord2i(0, 0);
        glVertex3f(float(x), 0 + shift_y, float(z));
        glTexCoord2i(1, 0);
        glVertex3f((float(x) + 1), 0 + shift_y, float(z));
        glTexCoord2i(1, 1);
        glVertex3f((float(x) + 1), 0 + shift_y, (float(z) + 1));
        glTexCoord2i(0, 1);
        glVertex3f(float(x), 0 + shift_y, (float(z) + 1));

        glEnd();
        texture_disable();
        index++;

      }
    }
    /*arr_counter += 8;
    std::cout << arr_counter << std::endl;
    glRotatef(four_coord[arr_counter - 8], four_coord[arr_counter - 7], four_coord[arr_counter - 6], four_coord[arr_counter - 5]);
    glRotatef(four_coord[arr_counter - 4], four_coord[arr_counter - 3], four_coord[arr_counter - 2], four_coord[arr_counter - 1]);
    shift_x = middle_point * cooord[i].first.first;
    shift_z = middle_point * cooord[i].first.second;
    shift_y = middle_point * cooord[i].second;*/
  
    glRotatef(90.0, 0.0, 0.0, 1.0);
    shift_x = middle_point * -1;
    shift_z = middle_point * 0;
    shift_y = middle_point * 1;
    for (int z = 0 - shift_z - middle_point; z < rubic_size - shift_z - middle_point; z++) {
      for (int x = 0 - shift_x - middle_point; x < rubic_size - shift_x - middle_point; x++) {
        texture_blind_and_enable(textures[colors[index]]);
        glBegin(GL_POLYGON);

        glTexCoord2i(0, 0);
        glVertex3f(float(x), 0 + shift_y, float(z));
        glTexCoord2i(1, 0);
        glVertex3f((float(x) + 1), 0 + shift_y, float(z));
        glTexCoord2i(1, 1);
        glVertex3f((float(x) + 1), 0 + shift_y, (float(z) + 1));
        glTexCoord2i(0, 1);
        glVertex3f(float(x), 0 + shift_y, (float(z) + 1));

        glEnd();
        texture_disable();
        index++;
      }
    }
    
    glRotatef(90.0, 0.0, 0.0, 1.0);
    shift_x = middle_point * 1;
    shift_y = middle_point * -3;
    shift_z = middle_point * 0;
    for (int z = 0 - shift_z - middle_point; z < rubic_size - shift_z - middle_point; z++) {
      for (int x = 0 - shift_x - middle_point; x < rubic_size - shift_x - middle_point; x++) {
        texture_blind_and_enable(textures[colors[index]]);
        glBegin(GL_POLYGON);

        glTexCoord2i(0, 0);
        glVertex3f(float(x), 0 + shift_y, float(z));
        glTexCoord2i(1, 0);
        glVertex3f((float(x) + 1), 0 + shift_y, float(z));
        glTexCoord2i(1, 1);
        glVertex3f((float(x) + 1), 0 + shift_y, (float(z) + 1));
        glTexCoord2i(0, 1);
        glVertex3f(float(x), 0 + shift_y, (float(z) + 1));

        glEnd();
        texture_disable();
        index++;
      }
    }
    
    glRotatef(90.0, 0.0, 0.0, 1.0);
    shift_x = middle_point * 2;
    shift_y = middle_point * 2;
    shift_z = middle_point * 0;
    for (int z = 0 - shift_z - middle_point; z < rubic_size - shift_z - middle_point; z++) {
      for (int x = 0 - shift_x - middle_point; x < rubic_size - shift_x - middle_point; x++) {
        texture_blind_and_enable(textures[colors[index]]);
        glBegin(GL_POLYGON);

        glTexCoord2i(0, 0);
        glVertex3f(float(x), 0 + shift_y, float(z));
        glTexCoord2i(1, 0);
        glVertex3f((float(x) + 1), 0 + shift_y, float(z));
        glTexCoord2i(1, 1);
        glVertex3f((float(x) + 1), 0 + shift_y, (float(z) + 1));
        glTexCoord2i(0, 1);
        glVertex3f(float(x), 0 + shift_y, (float(z) + 1));

        glEnd();
        texture_disable();
        index++;
      }
    }

    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(90.0, 0.0, 1.0, 0.0);

    shift_x = middle_point * 0;
    shift_y = middle_point * -1;
    shift_z = middle_point * 2;
    for (int z = 0 - shift_z - middle_point; z < rubic_size - shift_z - middle_point; z++) {
      for (int x = 0 - shift_x - middle_point; x < rubic_size - shift_x - middle_point; x++) {
        texture_blind_and_enable(textures[colors[index]]);
        glBegin(GL_POLYGON);

        glTexCoord2i(0, 0);
        glVertex3f(float(x), 0 + shift_y, float(z));
        glTexCoord2i(1, 0);
        glVertex3f((float(x) + 1), 0 + shift_y, float(z));
        glTexCoord2i(1, 1);
        glVertex3f((float(x) + 1), 0 + shift_y, (float(z) + 1));
        glTexCoord2i(0, 1);
        glVertex3f(float(x), 0 + shift_y, (float(z) + 1));

        glEnd();
        texture_disable();
        index++;
      }
    }
    
    glRotatef(180.0, 1.0, 0.0, 0.0);

    shift_x = middle_point * 0;
    shift_y = middle_point * -2;
    shift_z = middle_point * -1;
    for (int z = 0 - shift_z - middle_point; z < rubic_size - shift_z - middle_point; z++) {
      for (int x = 0 - shift_x - middle_point; x < rubic_size - shift_x - middle_point; x++) {
        texture_blind_and_enable(textures[colors[index]]);
        glBegin(GL_POLYGON);

        glTexCoord2i(0, 0);
        glVertex3f(float(x), 0 + shift_y, float(z));
        glTexCoord2i(1, 0);
        glVertex3f((float(x) + 1), 0 + shift_y, float(z));
        glTexCoord2i(1, 1);
        glVertex3f((float(x) + 1), 0 + shift_y, (float(z) + 1));
        glTexCoord2i(0, 1);
        glVertex3f(float(x), 0 + shift_y, (float(z) + 1));

        glEnd();
        texture_disable();
        index++;
      }
    }
    
}

void Cube_drawer::draw_background() {
}
