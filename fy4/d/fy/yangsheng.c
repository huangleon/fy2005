
inherit ROOM;
#include <room.h>

void create()
{
    set("short", "������");
    set("long", @LONG
�������ıڽԿգ�Ψǽ��������������У��������ޡ���ɫ��ɫ�������пա�
����Ϊ�У�����Ϊ�ޡ�ɫ��Ϊɫ���ǿ�Ϊ�ա��ռ���ɫ��ɫ����ɫ��ɫ�޶�ɫ��ɫ
���ǿա����޶��գ��ռ���ɫ��֪�ղ��գ�֪ɫ��ɫ��
LONG
    );
    set("exits", ([
	"south" : __DIR__"pusheng",
      ]));
    set("objects", ([
	__DIR__"npc/huofe" : 1,
      ]) );

    set("coor/x",-20);
    set("coor/y",-220);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}
