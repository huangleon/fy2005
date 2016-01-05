#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("大西洋海图", ({ "haitu"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "幅");
				set("no_split",1);
				set("desc_ext2","║│大西洋(1:100000000) 　　　　　　　　　　　　　　　　│║
║│　　　　　　　　　　　　　　　　　　　　　　　　　　│║
║│　　　　　　　　　　　　　　　　　"HIR"○"NOR CYN"　　　　　　　　│║\n");

                set("long", CYN"
                                         ~
        
             ~

                               ~   ~
                           
 
                   ～     ～          ～
          ～  ～   

               ～              ～      

   ～     ～           ～       ～             ～
        \n"NOR	);
                set("value", 1000);
				set("desc_ext","不明(???)");
        }
        ::init_item();
}


