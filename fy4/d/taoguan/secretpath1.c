// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���幬�ܵ�");
	set("long", @LONG
��̧���ۣ������Լ�����һ����խ����֮�У����������ߣ���ȴ��һ
�����¡��������ڶ�����ʯ����������֮���ָб�����һ˿����������������
��������������˸�ż�����̵��׹⣬��һƬ������Ե÷���������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"secretpath2",
]));
	set("coor/x",-20);
	set("coor/y",20);
	set("no_fly",1);
	set("coor/z",-10);
	setup();
	replace_program(ROOM);
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

