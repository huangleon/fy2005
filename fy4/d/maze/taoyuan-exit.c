// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
ԭ����ݵ���Ȼ���һ����У����������е�һҶ���ۣ������������һ����ۺ�
ɫ�Ļ���Ʈ���ڿ��У�����Ҳ����һ���������̺����һ��꣬�����г�����Ũ
�صĻ��㣬������֮�У�һ�Ƹ��������ǵĵ��������������ڻ����У������У���
�����С������ݵؾ�ͷ�Ǽ�ľ�ݣ���С��ֻ�ݵ��������ˡ�
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"north" : __DIR__"taoyuan-maze/exit",
		"south":  __DIR__"taoyuan-end",
	]));
        set("item_desc", ([
        	"house":	"�һ����У�һ��СС��ľ�ݡ�\n",
        	"cabin":	"�һ����У�һ��СС��ľ�ݡ�\n",
        	"ľ��":		"�һ����У�һ��СС��ľ�ݡ�\n",
        	"south":	"�һ����У�һ��СС��ľ�ݡ�\n",
        	
	]) );
	set("NONPC", 1);
	set("coor/x",-80);
	set("coor/y",-110);
	set("coor/z",-10);
	setup();
//	create_door("south", "door","ľ��", "north", DOOR_CLOSED);

}


int	valid_leave(object who , string dir) {
	object room, meihuadao;
	mapping doors;
	
	if (dir == "south") 
	{
/*		doors = this_object()->query_doors();
                if (doors["south"]["status"]==1)
                        return notify_fail("С�ݵ��Źصý����ġ�\n");*/
		room = find_object(__DIR__"taoyuan-end");
                if (room && room->usr_in())
			return notify_fail("ľ��̫С���ݲ�����ô���ˡ�\n");
		if (!REWARD_D->riddle_check(who,"�һ���̽��"))
			return notify_fail("��̽ͷ��ľ���п��˿���ûʲô�Źֵĵط���\n");
		if (room) {
			if (meihuadao = present("meihuadao",room))
			if (!userp(meihuadao))	
				destruct(meihuadao);
			room->reset();
		}
	}
	return ::valid_leave(who,dir);
}

void init()
{
        if(interactive(this_player()))
        {
                remove_call_out("dropleaf");
                call_out("dropleaf",random(10)+10,this_player());
        }
}

int dropleaf(object me)
{
        object leaf;
        if(me)
        if(environment(me) == this_object())
        {
                message_vision(WHT"�����֦������Ƭ�һ���׷������Ʈ��������Ʈ����ķ��ң�������ļ�ͷ��\n"NOR,me);
		message_vision(WHT"��ȥ����������Ʈ�㣬���Ƿ�Ҳ�����һ���һ�㣬������Ȼһ������������\n\n"NOR,me);
        }
	return 1;
}
	