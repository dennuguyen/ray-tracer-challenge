#include <iostream>

#include "canvas.hpp"
#include "environment.hpp"
#include "projectile.hpp"
#include "test_canvas.hpp"
#include "test_projectile.hpp"

void test_projectile(void)
{
    std::cout << "Testing ppm creation" << std::endl;

    colour::Colour proj_col(1.0, 0.0, 0.0);    
    canvas::Canvas c(900, 550);

    shapes::Projectile proj;
    shapes::Environment env;

    while(proj.get_pose().y > 0)
    {
        proj.set_pose(proj.get_pose() + proj.get_head());
        proj.set_head(proj.get_head() + env.get_gravity());
        proj.set_head(proj.get_head() + env.get_wind());
        
        canvas::write_pixel(c,
                            c.get_width() - proj.get_pose().y,
                            c.get_height() - proj.get_pose().z,
                            proj_col);
    }

    touch_ppm(c);

    std::cout << "Passed!" << std::endl;
}
