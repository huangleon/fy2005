inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIG"������"NOR);
    set("long", @LONG
����Ƕ��������ɵĵط�����Ϊ�����ǽ�ʨ�ھ֣���Ϊ��ʨ�ھ�����һ�л���
̫���Ļ�������׺�ȭ����ϱ��ľ�������ʨ�ơ����ͣ�����Ϊ��ʨ�ھ����߽�
����ʮ�꣬���СС����û�ж���һ֧�ڡ���������������Ĵ󲿷ֶ����������У�
���������Ľ�����������м��ҵ��̣����ǽ�ʨ�ھֵĲ�ҵ��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"ecloud4",
	"west" : __DIR__"ecloud3",
	"north" : __DIR__"afa",
      ]));
    set("objects", ([
	__DIR__"npc/xfan" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",200);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fyeast");
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

