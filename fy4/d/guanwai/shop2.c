#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"��Ŀ����"NOR);
    set("long", @LONG
СС�ĵ��̲�����ƺ����������Ų���İ��̺����Ͳ��������Զ��������ʱ
�����죬һ���������Ʈ����С����ӯ����Ũ����������Ϣ��������۸��ֲ���
��ף��������������ƿ������񡢰��κ����������һ��ҡ��������ת��Ͳ��
���������΢Ц�ؿ����㡣
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"octo3",
      ]));
    set("objects", ([
	__DIR__"npc/cloth" : 1,
      ]) );

	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
    setup();
    replace_program(ROOM);

}

// ���p��dancing_faery@hotmail.com
