#include <ansi.h>
inherit ROOM;

int room_check(object room);

void create()
{
        set("short", "��������");
        set("long", @LONG
ʲôҲ��������һƬ��ڵ�ˮ�ף�����
LONG
        );
    	set("exits", ([
        	"up" : __DIR__"lake",
    	]) );
    	set("no_fly", 1);
	set("coor/x",20);
	set("coor/y",80);
	set("coor/z",-60);
	set("underwater",100);
	set("water_damage",20);
    	setup();
}



/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
