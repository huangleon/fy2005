#include <room.h>
inherit DOOR_ROOM;
void create()
{
    set("short", "�ھֺ�Ժ");
    set("long", @LONG
�����ǽ�ʨ�ھֵĺ��ţ�ƽʱ���ǹص�����ʵʵ��ֻ�е��ھֽӵ�ʲô���ܶ�
���صĺ���󣬲����ھ����һ��һ����ͷ�Ӻ��������뿪���������Ŀ���Ҳ��
�����ܣ���Щ��֪��������˺������Ϳ������������������һ���ӵ�ˮ���
��Ҳ���������ˡ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"gke1",
	"north" : __DIR__"ecloud4",
      ]));
    set("objects", ([
	//        __DIR__"npc/resting_biao" : 2,
	//        __DIR__"npc/biaotou1" : 1,
      ]) );
    set("coor/x",240);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    create_door("north", "door","����", "south", DOOR_CLOSED);
}
