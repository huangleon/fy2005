// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "�ͷ���");
    set("long", @LONG
�ߵ�����㵫��ɽ�Ͽ��ݵķ�����ʱ������ԭ����һ����Ƿ���Ĵ�ʯ
�����ڷ��֮�ϣ�Ҳʹ�õ����������ڴ˶ѻ�������ס������ߡ���ʯ��һ��
��Լ�������֣�������ȥ��д���ǣ�
LONG
HIR
@LONG
������������������������֮��֮��ǰ����Ԩ��
LONG
NOR
        );
	set("objects", ([


	]));
	set("item_desc", ([
		"west":"���صĴ����赲ס������ߡ�\n",
		"northdown":"���صĴ����赲ס������ߡ�\n"

	]) );
	set("exits",([
  		"west" : "bridge",
  		"northdown" : "forest4",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",-40);
	set("coor/y",20);
	set("coor/z",80);
	setup();
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


