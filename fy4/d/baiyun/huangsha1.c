//Sinny@fengyun 2003 
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIB"�̺�"+HIY"��ɳ"NOR);
    set("long", @LONG
������ȥ��������ӣ���ϼѤ�ã����������֮�䣬������Ҳ����ǧ��Ƭ��ʵ�
���ˡ�һֻ��Ÿ��������𣬳����˺�������������ǵ��ഺһ�㣬һȥ���ٻ�ͷ��
�����ǽ�ӲӵĻ�ɳ���������ϵ���ͯ���Ž�Ѿ�������Ų�֪����ͯҥ�����ĸ���
���ź������������
LONG
    );
    set("exits", 
      ([ 
	"south" : __DIR__"baiyunentrance",
	"west" : __DIR__"tianya",
	"east" : __DIR__"haijiao",
	"north" : __DIR__"baiyundu",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/fishboy" : 2,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y",-10);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
