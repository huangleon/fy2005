// Tie@fengyun
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
�߹�խ�ţ�ǰ����һ���ƾɵ����ݣ������ﳱʪ������������ʮ��խС����ֻ
��һ����һ����һ�ʣ����Ե��ı���Ȼ���ն���į��Ҳ�ĵ���һյ�µƸ���ư�����
���ϵĻ���δ����ǽ���ϻ�����������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"southwest" : __DIR__"stone2",
      ]));
    set("objects", ([
	__DIR__"npc/yan": 1, 
	__DIR__"obj/bcloth": 2, 
      ]) );
    set("coor/x",260);
    set("coor/y",100);
    set("coor/z",0);
    set("map","fyeast");
    setup();

}
