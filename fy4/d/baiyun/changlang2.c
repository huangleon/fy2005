//Sinny@fengyun 2003 
//All Rights Reserved ^_^
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "��");
    set("long", @LONG
����¥�������ڣ�˭Ҳ�޷��������֮�о�Ȼ�����һ����ֱ���ĳ���������
�Ե��Ų���ĳ����ƣ������䲻��������Ҳ�ɱ��·���ƺ���������ɽ������Ȼ��Ѩ
������ɣ��˹����䴦������խ����ʱȴ��Ȼ������ֻ�����н��ͣ����г�������ˮ
֮��������������ö��������������ǰ���ƺ���Щ��ƹ����������
LONG
    );
    set("exits", 
      ([ 
	"north" : __DIR__"changlang",
	"south" : __DIR__"changlang3",
	"west" : __DIR__"changlangx",
	//       "enter" : __DIR__"mysticroom",
      ]));
    set("objects", 
      ([ 
	//       __DIR__"npc/jianchi" : 1,
      ]));

    set("indoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-260);
    set("coor/z",30);
    setup();
}

/*
int	valid_leave(object who, string dir)
{
    object me;
    me = who;
    if (dir == "west" && REWARD_D->riddle_check(who,"��ͼһ��") !=12)
    {
	tell_object(me,"�������̫�����������ǲ�ȥΪ�\n");
	return notify_fail("");
    }
    return ::valid_leave(who,dir);
}

*/
/*

	       (\~~~/)            
	       ( ����)        

	       (_____)~��      

��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
