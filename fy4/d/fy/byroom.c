#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "�����й�");
    set("long",  @LONG
�����ĵش���������������ε��������ϣ������ڰ�����ľ������������
��ͥ������ϴ��غ������С����Զ�ں���İ��Ƶ�û���κ���ϵ������֮��Ҳ��
�������еĴֺ�֮�������ǳ����и�ϲ���ۻ����ѣ������޶ȵ������˻��ڼ�����
�ӵĴ�ӵ֮�µ���Сס��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"ponder",
      ]));
    set("indoors", "fengyun");
	set("no_fight",1);
    set("objects", ([
	__DIR__"npc/princess": 1,
	__DIR__"npc/eunuch": 1,
	__DIR__"npc/duangonggong":1,
      ]) );

    set("coor/x",40);
    set("coor/y",100);
    set("coor/z",0);
    set("map","fynorth");
    setup();
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
