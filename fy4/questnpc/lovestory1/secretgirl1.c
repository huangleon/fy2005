inherit __DIR__"heroine";
#include <ansi.h>
void create()
{
	set_name("����Ů��",({"secret girl","girl"}) );
	set("long", "���޲��ɷ�������ݣ���ȴ��ӡ��һ˿�������ǳ\n");
	::create();
	setup();
	carry_object(__DIR__"obj/white_cloth")->wear();
}
	
void kill_him(object me);
	
mapping *event_list=({
	([	"question": "name",
		1: ([	1: ({"command","hmm",	}),
		]),
	]),
	([	"question": "age",
		1: ([	1: ({"message","$N����һ�����������$n��\n",})
		]),
	]),
	([	"question": "here",
		1: ([	1: ({"command","hmm",}),
			2: ({"delay",5}),	
			3: ({"message",CYN"$N˵������������أ���\n"NOR,}),
		]),
	]),
	([	"events": "sigh",
		1: ([	1: ({"message",HIY"$N��ͷ̾����������ǳ����ҹ��Ϊ˭��¶����������\n"NOR}),
			2: ({"delay",5}),
			3: ({"function","leave_room"}),
		]),
	]),
	([	"events": "sigh2",
		1: ([	1: ({"message",HIM"$N����Ŀ������ĵ��ǿգ��ƺ���ȫû��ע�⵽�����˵Ĵ��ڡ���\n"NOR}),
			2: ({"delay",5}),
			3: ({"function","leave_room"}),
		]),
	]),
	([	"events": "sigh3",
		1: ([	1: ({"message",HIW"$N����������������\n"NOR}),
			2: ({"delay",5}),
			3: ({"function","leave_room"}),
		]),
	]),
	([	"events": "sigh4",
		1: ([	1: ({"message",HIW"$N����������������\n"NOR}),
			2: ({"delay",5}),
			3: ({"function","leave_room"}),
		]),
	]),
	([	"events": "sigh5",
		1: ([	1: ({"message",HIW"$N����������������\n"NOR}),
			2: ({"delay",5}),
			3: ({"function","leave_room"}),
		]),
	]),
});
	
mapping query_answers(string topic)
{
	int i;
	
	for(i=0;i<sizeof(event_list);i++)
		if(event_list[i]["question"]==topic)
			return event_list[i];
	return 0;
}

mapping query_events(string topic)
{
	int i;
	
	for(i=0;i<sizeof(event_list);i++)
		if(event_list[i]["events"]==topic)
			return event_list[i];
	return 0;
}


void kill_him(object me)
{
	kill_ob(me);
}

void init()
{
	object me;
	
	::init();
	me=this_player();
	if(me==query("event_person")&&interactive(me))
	switch(me->query("lovestory1/event_meet_count"))
	{
		case 1:
		event_action(me,"sigh");
		break;
		
		case 2:
		event_action(me,"sigh2");
		break;
		
		case 3:
		event_action(me,"sigh3");
		break;
		
		case 4:
		event_action(me,"sigh4");
		break;
		
		case 5:
		event_action(me,"sigh4");
		break;
	}
}