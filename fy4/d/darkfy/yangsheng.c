
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "������");
        set("long", @LONG
�������ıڽԿգ�Ψǽ��������������У��������ޡ���ɫ��ɫ�������пա�����
Ϊ�У�����Ϊ�ޡ�ɫ��Ϊɫ���ǿ�Ϊ�ա��ռ���ɫ��ɫ����ɫ��ɫ�޶�ɫ��ɫ���ǿա�
���޶��գ��ռ���ɫ��֪�ղ��գ�֪ɫ��ɫ��
LONG
        );
        set("exits", ([
                "south" : __DIR__"pusheng",
        ]));
        set("objects", ([
                __DIR__"npc/" : 1,
        ]) );

        set("coor/x",-10);
        set("coor/y",-49);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);

}
