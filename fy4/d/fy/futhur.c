inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", "����");
    set("long", @LONG
���Ƕ�������ñȽ����ɵĽ���������ɫ�ܹ֣�һ��Ѫɫ�����İ���ɫ������
���ǹ���ɭɭ�������޴���һյ�͵ƺ�����������̫������ͼΪ�׵���������׭��
�����ĸ��֡������Ѳ�����Ҳ�������޹�ĺ�ɫ��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"yulong31",
      ]));
    set("objects", ([
	__DIR__"npc/dashi" : 1,
      ]) );

    set("coor/x",260);
    set("coor/y",40);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
