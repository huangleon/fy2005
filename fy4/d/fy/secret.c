inherit DOOR_ROOM;
#include <room.h>
void create()
{
    set("short", "����");
    set("long", @LONG
���Ӳ�������һ�Ŵ���һ�����ӡ����������û�д��������ǽ�ھ���Ȼȫ��
�Ǻü��������塣�����ϻ�����һ����ľ���Ӻ�һЩ�Ʋˣ��Ʋ˾�Ȼȫ��ԭ�ⲻ����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"zhoulang",
      ]));
    set("objects", ([
	__DIR__"npc/blue" : 1,
	__DIR__"npc/fangyuxiang" : 1,
      ]) );

    set("coor/x",-190);
    set("coor/y",-30);
    set("coor/z",-10);
    setup();
    //door here
    create_door("south", "door","������", "north", DOOR_CLOSED);

}
