
.. _program_listing_file_engine_EntryPoint.cpp:

Program Listing for File EntryPoint.cpp
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_engine_EntryPoint.cpp>` (``engine/EntryPoint.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #include <Engine/Core.hpp>
   
   int main(int argc, char* argv[]) {
       Engine::Core engine;
       engine.Run();
   
       return 0;
   }
