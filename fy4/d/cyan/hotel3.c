// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "�ĺ���ջ��¥");
    set("long", @LONG
���϶�¥��ֻ������ջ�����οգ���������Ĵ���֧�����ݶ�����������
ʤ��ͤ�󡣷����������ҵذ��ż������Σ�С��������һ�����ϣ���Ŀ���¡�
һ����ǿ����ɽ�������������ͻȻ���������ڴ˴�ƾ��ʹ�����ؽ�Ϊ����һ
�����£�������ա�
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/desk2":1,
	__DIR__"obj/chair":2,
	__DIR__"npc/wailencer":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"down" : __DIR__"hotel2",
	]) );

	//565698


	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",100);
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


