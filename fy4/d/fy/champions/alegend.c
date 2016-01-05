#include <ansi.h>
inherit ROOM;

void create()
{

	set("class","legend");

  set ("short", HIY"æµ÷Æªÿ¿»"NOR);

   set("long", WHT @LONG

°°°°°°°°°°°° ∂∑æ∆…Ë√’∆¥µ∂∑®°°°°

°°°°°°“¬”∞∑…—Ô“˛¬Æ·€


LONG
NOR    );
    set("exits", ([ 
	"down" : "/d/fy/mirrorgallery",
      ]));

  	set("objects",([
		__DIR__"npc/"+query("class") : 1,
	]));


	set("no_fly",1);
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",240);
	set("coor/z",20);
    set("map","fynorth");
    setup();
}







/*

°°°°°°     /£‹              £Ø\      
°°°°°°   ®ä   £‹£ﬂ£ﬂ°°°°°°£Ø  ¶Ú       
°°°°°°   ®ä £Ø£˛    ®ê®Ä®Ä®è®v¶Ú       
°°°°°°    ®M                  ©Ö       
°°°°°°    ¶Ù   /£˛\    /£˛\   ®ä      
°°°°°°    ¶Ù   ¶Ù°Ò    °Ò  ¶Ù ®ä       
°°°°°°   ©‡    \ /    \°°/    ©‡      
°°°°°°    ©Ö°°      °Ò      °°®M         
°°°°°°    °•®v°°    °°   °°£Ø°•         
°°°°°°    ®q©§®è°•°•°•£˛®ê®è©Ö           
°°°°°°   £®   ¶Ù           /¶Â¶Â\®ç®Ä    
°°°°°°  £®____¶Ù  ®ä £Ø  ®ä .. ®Ä®è     
°°°°°°        \¶‰¶‰/ ¶„¶„¶„£‹°Ò£Ø         
                       °•             
°°°°°°°°°°°°°°°°- FengYun - °°°°°°
 °°°°°°°°°°°°°°annie 06.2005
 °°°°°°°°dancing_faery@hotmail.com

*/

