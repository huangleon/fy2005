// marry_room.c
// tie@fengyun
#include <room.h>
inherit ROOM;
string look_sign(object me);
void create()
{
        set("short", "ԧ��ͤ");
        set("long", @LONG
��������վ��ԧ��ͤ�������ר�����˵޽��Լ�ͽ����Լ�ĵط���
�������еķ򸾶���������ϲ����Ե�ģ�������������Ҳ�����Ľ��������
�����ˣ������ſڵĵط���һ����ľ��ɵ����ƣ�������
LONG
        );
        set("exits", ([
                "north"          : __DIR__"ecloud1", 
         ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        set("objects", ([
                __DIR__"npc/mei_po" : 1,
        ]) );
 
        set("coor/x",10);
        set("coor/y",-1);
        set("coor/z",-300);
        setup();

}

string look_sign(object me)
{
        return "�޽ᣨ����������������������壩��Լ��\n";
}

