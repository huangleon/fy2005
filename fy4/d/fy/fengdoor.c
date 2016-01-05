#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIW"��̳"NOR);
    set("long", 
"��̳�˽�Ǯ��������Ρ��׳�ۣ�̳��������ʣ������ŷ����Ϲٽ�罨�˷�
̳��������Զ���������̳��Ȼ���⻹����������ߵĽ�����ԶԶ����Ǯ�����̳
����ȥ��һ���������ƵĻƽ������չ��½�̻Իͣ������������Ϲٺ��绽�꣬Ȩ
�㳯Ұ��Ұ����Ȼ���ҡ���̳���Ҷ���������С���֣�"+HIW"

                      ��          ̳
                   
"NOR        );
        set("exits", ([ /* sizeof() == 4 */
  		"west" : __DIR__"wcloud1",
  		"east" : __DIR__"fysquare",
  		"north" : __DIR__"poemp",
  		"south" : __DIR__"mailst",
]));
        set("outdoors", "fengyun");
        set("objects", ([
//        __DIR__"npc/mei": 1,
                        ]) );

  	set("coor/x",-40);
  	set("coor/y",0);
	set("coor/z",0);
 	set("map","fywest");
	setup();

}

int valid_leave(object me, string dir)
{
        object ob,room;
        int i;
        mapping condition;
        string *type;
        if( userp(me) && dir == "north")
		{
			condition = me->query_all_condition();
			if( mapp(condition) ) {
				type=keys(condition);
				for (i=0;i<sizeof(type);i++) {
					if (type[i]!="drunk" && type[i]!="buffed" && type[i]!="bandaged")
						return notify_fail("����ּ������ý���̽��ʫ̨��\n");
				} 
	      	}	
	
			if(me->query("eff_sen")<me->query("max_sen")*95/100
				||me->query("eff_kee")<me->query("max_kee")*95/100
				||me->query("eff_gin")<me->query("max_gin")*95/100 )
				return notify_fail("���˺����ۣ�̽��ʫ̨������ķس���\n");
		
			tell_object(me,HIR"������˱����������̽��¥��¥�ڿ����ɽ�ɱ����������ʧ��\n\n"NOR);
		
		}	
		return 1;
}
