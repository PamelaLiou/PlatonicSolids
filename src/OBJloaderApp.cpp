#include "Resources.h"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Camera.h"
#include "cinder/ObjLoader.h"
#include "cinder/gl/Texture.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class OBJloaderApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    TriMesh weave;
	gl::Texture		mTexture;

    
};

void OBJloaderApp::setup()
{
    gl::enableDepthRead();
    gl::enableDepthWrite();
    //setFullScreen( true );
    ObjLoader loader( loadResource("ambient_working?.obj" ));

   // ObjLoader loader( loadResource("ambient_working_a.obj" ), loadResource("ambient_working_a.mtl"));
    mTexture = gl::Texture( loadImage( loadResource( "baked_d.tif" ) ) );

//    ObjLoader loader( loadResource("warpup.obj" ), loadResource("warpup.mtl" ));
	loader.load( &weave );
    


}

void OBJloaderApp::mouseDown( MouseEvent event )
{
}

void OBJloaderApp::update()
{
}

void OBJloaderApp::draw()
{

    gl::clear( Color( 0, 0, 0 ) );
    
//    gl::setMatricesWindow( getWindowSize() );
//    
//    gl::enableAlphaBlending();
//    
//    gl::color( 1,1,1 );
    
//    glEnable( GL_TEXTURE_2D );
//    gl::pushMatrices();
//    mTexture.bind();
//        gl::scale( Vec3f(7.0, 7.0, 7.0 ));
//        gl::draw( weave );
//
////    gl::drawSolidRect( getWindowBounds() );
//    mTexture.unbind();
//    
//    glDisable( GL_TEXTURE_2D );
//    gl::popMatrices();
    
    //1
    {
        for (int j = 1; j < 10; j++){
            for(int i = 1; i <100; i ++){
                gl::pushMatrices();
                gl::translate ( (70 *i), (70*j) );
                gl::scale( Vec3f(7.0, 7.0, 7.0 ));
                
                
                gl::pushMatrices();
                gl::rotate( Vec3f(0.0, getElapsedSeconds() * (20 *i), 0.0 ));
                // clear out the window with black
                glEnable(GL_TEXTURE_2D);
                mTexture.bind();

                gl::draw( weave );
                mTexture.unbind();
                
                glDisable(GL_TEXTURE_2D);

                gl::popMatrices();
                
                
                //gl::clear( Color( 0, 0, 0 ) );
                gl::popMatrices();
            }
        }
    }
////2
//    gl::pushMatrices();
//    gl::rotate(Vec3f(180,0,0));
//    gl::translate(Vec3f(0.0,500,0.0));
//    {
//        for (int j = 1; j < 60; j++){
//            for(int i = 1; i <60; i ++){
//                gl::pushMatrices();
//                gl::translate ( (9 *i), (9*j) );
//                gl::scale( Vec3f( 0.75, 0.75, 0.75 ));
//                
//                
//                gl::pushMatrices();
//                gl::rotate( Vec3f(0.0, getElapsedSeconds() * (20 *i), 0.0 ));
//                // clear out the window with black
//                gl::draw( weave );
//                
//                gl::popMatrices();
//                
//                //gl::clear( Color( 0, 0, 0 ) );
//                gl::popMatrices();
//            }
//        }
//    }
//    gl::popMatrices();
    
    
    
    
    
    
    
//    
//    
//    {
//        gl::pushMatrices();
//        gl::translate(getWindowWidth()/2, 0,0);
//
//        gl::rotate(Vec3f(180,0,0));
//        
//        for (int j = 1; j < 60; j++){
//            for(int i = 1; i <60; i ++){
//                gl::pushMatrices();
//                gl::translate ( (9 *i), (9*j) );
//                gl::scale( Vec3f( 0.75, 0.75, 0.75 ));
//                
//                
//                gl::pushMatrices();
//                gl::rotate( Vec3f(0.0, getElapsedSeconds() * (20 *i), 0.0 ));
//                // clear out the window with black
//                gl::draw( weave );
//                
//                gl::popMatrices();
//                
//                //gl::clear( Color( 0, 0, 0 ) );
//                gl::popMatrices();
//            }
//        }
//        
//        gl::popMatrices();
//    }
//    
//    //3
//    
//    {
//        gl::pushMatrices();
//        gl::translate(getWindowCenter());
//
//        gl::rotate(Vec3f(180,180,0));
//        
//        for (int j = 1; j < 60; j++){
//            for(int i = 1; i <60; i ++){
//                gl::pushMatrices();
//                gl::translate ( (9 *i), (9*j) );
//                gl::scale( Vec3f( 0.75, 0.75, 0.75 ));
//            
//                gl::pushMatrices();
//                gl::rotate( Vec3f(0.0, getElapsedSeconds() * (20 *i), 0.0 ));
//                // clear out the window with black
//                gl::draw( weave );
//                
//                gl::popMatrices();
//                
//                //gl::clear( Color( 0, 0, 0 ) );
//                gl::popMatrices();
//            }
//        }
//        
//        gl::popMatrices();
//    }
//    
//    
//    //4
//    
//    {
//        gl::pushMatrices();
//        gl::translate(getWindowCenter());
//        
//        gl::rotate(Vec3f(180,180,0));
//        
//        for (int j = 1; j < 60; j++){
//            for(int i = 1; i <60; i ++){
//                gl::pushMatrices();
//                gl::translate ( (9 *i), (9*j) );
//                gl::scale( Vec3f( 0.75, 0.75, 0.75 ));
//                
//                
//                gl::pushMatrices();
//                gl::rotate( Vec3f(0.0, getElapsedSeconds() * (20 *i), 0.0 ));
//                // clear out the window with black
//                gl::draw( weave );
//                
//                gl::popMatrices();
//                
//                //gl::clear( Color( 0, 0, 0 ) );
//                gl::popMatrices();
//            }
//        }
//        
//        gl::popMatrices();
//    }
}

CINDER_APP_NATIVE( OBJloaderApp, RendererGl )
