#include <ansi.h>
inherit ROOM;

void create()
{


  set ("short", HIW"��֮����"NOR);

   set("long", HIR BLK @LONG
���ȵ����֮���ڷ���һ���Ȼөɫ����������˵������һ�����ӳ�ճ�����һ
������������R�ӣ�Ω���޷�ӳ��������ǰ���������������ˣ���Ҫ����һ����
ս������������սʤ���ң������ѧ�İ��ء�
LONG
NOR    );
    set("exits", ([ 
  "up" : __DIR__"mirrorgallery",
	"down" : __DIR__"hall",


      ]));

  	set("objects",([
		AREA_GUANWAI"npc/champion": 1,
//		__DIR__"champions/c"+query("floor") : 1,
	]));


	set("no_fly",1);
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",240);
	set("coor/z",10);
    set("map","fynorth");
    setup();
}




void init()
{
	add_action("do_north", "go");
}

int valid_leave(object who, string dir){
	
	if (dir == "down")
	{
		tell_object(who, HIW"�����뿪��������������У����ͣ�����������ս��״̬��\n\n"NOR);	
		who->remove_all_killer();
		who->perform_busy(1);
	}
	return ::valid_leave();
}

int do_north(string arg)
{
    object room, me;
	string str;
    if (arg == "up") {
	me = this_player();
	str = me->query("class");
	if (!str || str == "")
		str="mirrorgallery";
	else
		str = __DIR__"champions/a"+str;

	if (!room= find_object(str))
	    room=load_object(str);
	if (room)
		me->move(room);
		return 1;
    }
    return 0;
}





/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/

