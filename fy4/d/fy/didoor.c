#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",HIG "��̳"NOR);
    set("long", 
"����㳡�������Ƿ��Ƴ������̾�����۵Ķ������������Ź㳡Ϊ��̳���˷�
�ư��ռ������֮����̳���ղ������λ��ÿ�����ǰһ��Ž������������ĺ���
���µ���λ���ڼ�̨�ϡ�̳������������ƣ�����ϼε��̳������һ���������
�ݴ�������ٶ������ʷ����̳�������飺"+HIG"

                      ��           ̳
                  
"NOR
        );
        set("exits", ([ /* sizeof() == 4 */
  		"east" : __DIR__"ecloud1",
  		"south" : __DIR__"hiretem",
  		"west" : __DIR__"fysquare",
	]));
        set("outdoors", "fengyun");
 set("coor/x",40);
 set("coor/y",0);
	set("coor/z",0);
 set("map","fyeast");
	setup();

}
