#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "��Ӫ");
    set("long", @LONG
һ�Ű���ɫ��ƽ������������������פ�ط��ƳǱ�ʿ��Ӫ�أ���Ȼ˵������ǰ���
����ɽ��������������û����ʲô�󰸣�������֮�����ӽ��£����Ծ����ᶽ�µ�
��ӪС�䣬�޲�����ҵҵ��������Ǯ��������ʢ�������ｭ�����������ڶ࣬��ʿ
����ҹѲ�飬��Ӫ��������������յĲ���֮����		
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"ecloud5",
      ]));


    set("indoors", "fengyun");
    set("coor/x",280);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}

