inherit ROOM;
#include <ansi.h>
int check_legal_name(string arg);
void create()
{
        set("short", "����ͤ");
        set("long", @LONG
�������ٴ����Ϊ������ȡ�ñ���ʤ���ı�Ҫ����֮һ��
ÿ����һ�ȵķ��ƳǴ��������ǲ������˶��ᵽ�������һ��
���У�������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ecloud2",
]));
        set("objects", ([
        __DIR__"/npc/" : 1,
			]) );
        set("coor/x",20);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);

}
