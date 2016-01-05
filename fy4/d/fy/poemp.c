#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "̽��ʫ̨");
    set("long",  
"�����е��������ٴ�����ʫ�Դʵ��źá�ֻҪ������У��ͻ���ű�ī����
�������𣬵ȵ����է�������ǣ��ܱʼ��飬����ǧ�����䡣ʫ̨���������ľ��
�ݣ�" + YEL" 

                       �����оƽ���
                       �Ĺ����ս���ͷ��
                                       ���������ھƺ�ʧ��ʱ��
"NOR
        );
        set("exits", ([ /* sizeof() == 4 */
	      "south" : __DIR__"fengdoor",
		  "up": __DIR__"poemp2",
		]));
        set("objects", ([
        	__DIR__"npc/yaren" : 1,
			__DIR__"npc/prince" : 1,
			__DIR__"npc/sandbag" : 1,
        ]) );
	set("no_death_penalty",1);
	set("no_study",1);
	set("no_fly", 1);
	set("coor/x",-40);
  	set("coor/y",20);
	set("coor/z",0);
	set("map","fywest");
	set("PK_FREE", 1);
	setup();
    call_other( "/obj/board/poem_b", "???" );
}


int valid_leave(object who, string dir){
	
	// Don't die outside.
	if (who->query("kee")< 0 || who->query("sen")<0 || who->query("gin")<0)
		return 0;

	if (dir == "south")
	{
		tell_object(who, HIW"�����뿪��������������У����ͣ�����������ս��״̬��\n\n"NOR);	
		who->remove_all_killer();
		who->perform_busy(1);
	}
	return ::valid_leave();
}