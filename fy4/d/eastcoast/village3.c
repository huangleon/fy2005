#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
        set("short", "Сľ��");
        set("long", @LONG
һ��տյ��������������Сľ�ݣ���Ȼ����ʱ�����������ЪϢ��
���ݽǿ�ȥ��һ������ҷ�س�ȹ��Ů��������ҡҡ�����ľ�������Ŵ���
�������С���ڷ���һƿ�������޵�ɽ�裬����ӵ�ľ���Ѿ����ã���
������ӦƮ����ù������ζ��ȴֻ����һƿɽ������㡣
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"village2",
	]));
	set("item_desc", ([
	 ]));
	set("coor/x",900);
	set("coor/y",60);
	set("coor/z",0);
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

