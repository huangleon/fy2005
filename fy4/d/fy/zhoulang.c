inherit DOOR_ROOM;
#include <room.h>
void create()
{
    set("short", "ʯ����");
    set("long", @LONG
���ź���ʮ����ʯ�ף��������������������ȼ�ŵƣ��ƻ�������һ���š�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"secret",
	"eastup" : __DIR__"pianting",
      ]));
    set("coor/x",-190);
    set("coor/y",-40);
    set("coor/z",-10);
    setup();
    //door here
    create_door("north","door", "������", "south", DOOR_CLOSED);

}
