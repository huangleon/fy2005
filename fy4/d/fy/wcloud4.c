inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIW"�����"NOR);
    set("long", @LONG
���Ƴ������Թ�ı��ǽ�Ǯ����ܶ棬��������Ǯ�ﲻ��Ѹ������Ϊ�����е�
һ�����̻ᣬ���У���¥��ҵ�������ԣ�������𣬸������£������Ϲٽ��
�۾���Ƴǣ������������ϱ���֮�ơ���������Ļ��϶Դ�Ҳ�޿��κΣ���������
���������빬�з������硣
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west"  : __DIR__"wcloud5",
	"east"  : __DIR__"wcloud3",
      ]));

    set("objects", ([
	__DIR__"npc/beggar" : 3,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",-240);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
