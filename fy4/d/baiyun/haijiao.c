//Sinny@fengyun 2003 
//All Rights Reserved ^_^
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIB"����"NOR);
    set("long", @LONG
����ʲô��ɫ��
    ��ɫ��
    ���������ʲô��ɫ��
    Ҳ����ɫ��
    Ϊʲô��
    ��Ϊ����ֻ�б��ˡ�
LONG
    );
    set("exits", 
      ([ 
	"west" : __DIR__"huangsha1",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/meiyinxue" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",10);
    set("coor/y",-10);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
