#include <room.h>

inherit ROOM;

void create()
{
    set("short", "ӭ÷��ջ");
    set("long", @LONG
���ǲ�������������һ�ҿ�ջ����˵��ҵ�����һ������������ˡ�������
�￪��ջ����ϣ������������ԭʧɢ�������ܹ�֪�������������������ᡣ��
�ǿ�ջ��ҵ���꣬��ԭ������������������û�д������������˵�һ����Ϣ����Ϊ
�������˺��У���ջ�����嵭������������ϻҲ��������˳������ط��Ƴ�
�����⡣һ����ң��ӣɣǣΣ��������ڡ�
LONG
    );

    set("valid_startroom", 1);
    set("exits", ([
	"west"   : __DIR__"octo1",]) );
    set("item_desc",	([
	"sign"   : "����д������Ϊ����������(rent mache) ����8��\n",

      ]) );	

    set("objects", ([
	__DIR__"npc/waiter" : 1, 
	"/obj/npc/shusheng" :1,
	"/obj/npc/trashcan":1,
      ]) );

    set("coor/x",40);
    set("coor/y",-10);
    set("coor/z",0);
    setup();
    call_other( "/obj/board/common_a", "???" );
    //  replace_program(NEWBIE_HELP_ROOM);
}

