inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "ɽ��");
        set("long", @LONG
ɽ·�������ۣ�ת�˼������߽��ȿڣ���ɫ��Ȼһ�䣬����ʯ���������٣�
ɽɫ���䣬����ǧ�壬ֱ�������뵽��ԭ�ķ�⡣����ɽɽ�����վ���������·ȴ
����ش���Ⱥɽ����[37m���˹�[32m������������ȺɽΧ�ƵĹȵף�������ϸ��Ѱ�ң�����
���ֲ��ˡ�
LONG
        );
        set("exits", ([ 
	"southup" : __DIR__"valleyentry",
	"northdown" : __DIR__"road4",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",20);
        set("coor/z",40);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
