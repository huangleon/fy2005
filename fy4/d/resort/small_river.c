#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "С����ˮ");
        set("long", @LONG
һ���峺��СϪ�Ϻ����һ��ľ�š��ŵ��Ǳ���һƬïʢ�����֡���������÷
������ӳ֮�У�һ�����ɵ�ׯԺ�������֡�������������϶�������������[33m����[32m��
����ЩŮͯ������Ц����
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"gate",
  		"east" : __DIR__"another_sky",
		]));
		set("item_desc",([
			"����":	"԰����ĸ�������ô"MAG"��"NOR"�õ��أ�Ӧ���ǡ���������\n",
		]));
        set("outdoors", "resort");

		set("coor/x",0);
		set("coor/y",-30);
		set("coor/z",0);
		setup();
       
}


void init(){
	add_action("do_listen","listen");
}



int do_listen(){
	tell_object(this_player(),CYN"
԰�ں�Ȼ����һ��������ɽ֮ΡΡ��ˮ֮���󣬸���֮�������ָ�֮���ˣ�
��������ָ�£�������ȴ�˺쳾�ķ��ա�

ֻ��԰������˵����Զ���ǿͣ��������ɽׯһ��\n"NOR);
	this_player()->set_temp("resort_qin",1);
	return 1;
}


