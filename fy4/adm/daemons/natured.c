// natured.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/14/2001 by Daniel Q. Yu.
//		- 08/20/2001 by Daniel Q. Yu.
//			* put in weather system.

// We assume that our FengYun calendar is:
//		12 monthes per year
//		30 days per month
//		12 ʱ�� (2 hours) per day
//		4 �� (30 mins) per ʱ�� 
//		One min game == one sec real time.
//		Max year is about 4000 years (due to time() function)

#include <ansi.h>

mapping *day_phase = ({
	([	"start_at"	:	0,
		"event_msg"	: 	"���ƺ����������İ������",
		"desc_msg"	:	"ҹĻ�ʹ�������һƬ����",
	]),
	([	"start_at"	:	240,
		"event_msg"	: 	"������������𽥳�����һ˿��ǰס�",
		"desc_msg"	:	"��������ո���һ˿����ɫ",
	]),
	
	([	"start_at"	:	360,
		"event_msg"	: 	"���������Խ��Խ�����������ֺ�ɫ��",
		"desc_msg"	:	"��ϼ�ڶ����ĵ�ƽ���ϸ���",
	]),
	([	"start_at"	:	480,
		"event_msg"	: 	"����ƺ�Խ��Խ��ֱ�ˡ�",
		"desc_msg"	:	"����ʼ����˷����������Ѿ���������",
	]),
	([	"start_at"	:	660,
		"event_msg"	: 	"���������ߣ��ƺ��Ѿ��������ˡ�",
		"desc_msg"	:	"���絽�ˣ�æµ�������ƺ�������һЩ",
	]),
	([	"start_at"	:	900,
		"event_msg"	: 	"���߿�ʼ������ƫ����",
		"desc_msg"	:	"�����ƺ���ʼƫ��������",
	]),
	([	"start_at"	:	1080,
		"event_msg"	: 	"��ϼ�����������ӳ��һƬ��졣",
		"desc_msg"	:	"һ��������ϼ���ǻ��������ĵ�ƽ����",
	]),
	([	"start_at"	:	1260,
		"event_msg"	: 	"�԰׵Ĵ��������ȫ��û�����һ˿������",
		"desc_msg"	:	"ҹĻ���֣���Χ���������˺ڰ���",
	])
});

mapping *year_phase = ({
	([	"month"		: 	1,
		"day"		:	1,
		"event_msg"	:	"�µ�һ�굽�ˣ��������Ǻ�����ı�������",
		"desc_msg"	:	"����",
	]),
	([	"month"		: 	1,
		"day"		:	15,
		"event_msg"	:	"Ԫ���ڵ��ˣ��˼��ſڶ����˺��ĵ�����",
		"desc_msg"	:	"����",
	]),
	([	"month"		: 	3,
		"day"		:	10,
		"event_msg"	:	"�����ڵ��ˣ����︴�յ����������ڵ����Ĵ����",
		"desc_msg"	:	"����",
	]),
	([	"month"		: 	4,
		"day"		:	1,
		"event_msg"	:	"���ȵ����쵽�ˣ�Զɽ�������˴�������ɫ��",
		"desc_msg"	:	"����",
	]),
	([	"month"		: 	5,
		"day"		:	5,
		"event_msg"	:	"����ڵ��ˣ���Ҷ����ζƮ���ڽֵ��ϡ�",
		"desc_msg"	:	"����",
	]),
	([	"month"		: 	7,
		"day"		:	1,
		"event_msg"	:	"��ˬ�����쵽�ˣ�����ƺ��������ʸ�Զ��",
		"desc_msg"	:	"����",
	]),
	([	"month"		: 	7,
		"day"		:	7,
		"event_msg"	:	"��Ϧ�ڵ��ˣ���ҹ�������ǲ��ǻ��ú���ǳ��",
		"desc_msg"	:	"����",
	]),
	([	"month"		: 	7,
		"day"		:	15,
		"event_msg"	:	"��ڵ��ˣ������������ż���������Ϣ��",
		"desc_msg"	:	"����",
	]),
	([	"month"		: 	8,
		"day"		:	15,
		"event_msg"	:	"����ڵ��ˣ���ҹ��������Բ�ģ�Ҳ��������������Բ��һ�졣",
		"desc_msg"	:	"����",
	]),
	([	"month"		: 	9,
		"day"		:	9,
		"event_msg"	:	"�����ڵ��ˣ�����������ɫͿ�����ּ䡣",
		"desc_msg"	:	"����",
	]),
	([	"month"		: 	10,
		"day"		:	1,
		"event_msg"	:	"����Ķ��쵽�ˣ������У���������ſ����Ϸ�ȥ��",
		"desc_msg"	:	"����",
	]),
	([	"month"		: 	12,
		"day"		:	8,
		"event_msg"	:	"���˽ڵ��ˣ�������æµ��׼�����ꡣ",
		"desc_msg"	:	"����",
	])
});

mapping *weather_msg = ({
	({	([	"weather"	:	"��",
			"message"	:	({	"�����ˣ�������������ơ�",
								"�������������������٣����߰뿪����������������ݵ����㡣"}),
			"chance"	:	20,
			"length"	:	4,
		]),
		([	"weather"	:	"С��"	,
			"message"	:	({ 	"��ϡ��С��������֯�������������Χ��",
								"����׷����£�ʪ���ܵ����м������Ļ�ݺ���衣" }),
			"chance"	:	40,
			"length"	:	4,
		]),
		([	"weather"	:	"΢��"	,
			"message"	:	({ "�����΢����������գ����������ҷ�����Ϣ��",
								"��͵Ĵ��紵������Ĳ���Ҫ�ǻ���" }),
			"chance"	:	20,
			"length"	:	2,
		]),
		([	"weather"	:	"���",
			"message"	:	({ "ƽ������һ���󼱷磬�Ѷѻ���ѩ�����������������ա�" }),
			"chance"	:	10,
			"length"	:	1,
		]),
		([	"weather"	:	"���",
			"message"	:	({ "��պ�Ȼ����������Զ������͸����ɫ��\nͻȻ�䣬�����ŻƳ�����ǵض�����" }),
			"chance"	:	10,
			"length"	:	1,
		])
	}),
	({	([	"weather"	:	"��",
			"message"	:	({ "�����ˣ����䵭�����Ʋ�ױ�������ʵ���ա�",
								"����ӣ�ң����˰Ž����ľ�����ͻ��������"}),
			"chance"	:	30,
			"length"	:	4,
		]),
		([	"weather"	:	"����"	,
			"message"	:	({ 	"���׹��󣬼�������ǵض���������һ����������ࡣ",
								"�����������仨���أ�����ı����������������", 
								"����һ��������ı��������һ�ɻ����������Ѿõ�ŭ������������������" }),
			"chance"	:	20,
			"length"	:	2,
		]),
		([	"weather"	:	"����"	,
			"message"	:	({ 	"һ����ɫ�����⻬�������ܲ�����գ������ź�¡¡����������ʹ�����\n�������㻩���������¡�",
								"���Ʋ�ʱ�ı����绮����������������������ͷ����ը����\nת�ۼ���Ͼͻ���һ���ݵ���ˮ��"}),
			"chance"	:	10,
			"length"	:	1,
			"event" 	:	"event_summer_thunder",
		]),
		([	"weather"	:	"΢��"	,
			"message"	:	({ "�·�����Ϊ����ҡ���Ӱ㣬��ˬ��΢�����㾫��һ������ȫ����",
								"���Ҷ�������ķ������˵��֣����˿����ţ������������������Ѱ���" }),
			"chance"	:	15,
			"length"	:	2,
		]),
		([	"weather"	:	"���",
			"message"	:	({ "��������ι�ǰ������һȺ����׷��ĺ��ӣ������˺������ĳ�����" }),
			"chance"	:	20,
			"length"	:	1,
		]),
		([	"weather"	:	"����",
			"message"	:	({ "Զ���Ļ������ںڵ�ɽ�壬Ѹ��������ƽ���\nһ�����֮������������������ű�����к���¡�" }),
			"chance"	:	5,
			"length"	:	1,
			"event"		:	"event_summer_storm",
		])
	}),
	({	([	"weather"	:	"��",
			"message"	:	({ 	"�����ˣ������������Ʈ��Ʈȥ��",
								"������ʸ߾�����ˮ������ԶԶ�ģ��������������" }),
			"chance"	:	30,
			"length"	:	4,
		]),
		([	"weather"	:	"��"	,
			"message"	:	({ "�һҵ���գ���ʼ��������������������\nһ�ε����ڵ��ϵ������ƺ�����������" }),
			"chance"	:	10,
			"length"	:	2,
		]),
		([	"weather"	:	"΢��"	,
			"message"	:	({ "һ�����紵������Ƭ��Ҷ����Ʈ��������" }),
			"chance"	:	30,
			"length"	:	2,
		]),
		([	"weather"	:	"���",
			"message"	:	({ 	"��Ȼ֮�����һ���磬��Ҷ����������衣",
								"����ķ��Х���������Ƶı�����ա�",
								"���ں�Х��Х�������ӱޣ������˹��˵��ģ�Ҳ��ɢ�˹��͵Ļ��ǡ�" }), 
			"chance"	:	20,
			"length"	:	1,
		]),
		([	"weather"	:	"����",
			"message"	:	({ "�����ķ��Ȼ�����Щ���䣬����������׵�������£�\n��֦��Ҷ������þ��ΰ��������" }),
			"chance"	:	10,
			"length"	:	1,
		])
	}),
	({	([	"weather"	:	"��",
			"message"	:	({ 	"�����ˣ������Ʋ�ѻ�����ߡ�",
								"�������䣬˿˿÷������Ʈ�����������£���������ů�⡣" }),
			"chance"	:	25,
			"length"	:	4,
		]),
		([	"weather"	:	"ѩ"	,
			"message"	:	({ "һƬһƬ��ѩ�����Ƶ����ط������£����Ϻܿ������������ɫ��",
								"��ѩ�׷���������ţ������ĵģ�������Ϣ�ĸ�������" }),
			"chance"	:	25,
			"length"	:	1,
		]),
		([	"weather"	:	"΢��"	,
			"message"	:	({ "���󺮷紵������ֻ���������������Щ��ʹ��" }),
			"chance"	:	20,
			"length"	:	1,
			"event"		:	"event_winter_wind",
		]),
		([	"weather"	:	"���",
			"message"	:	({ "����Х�Ŵ������ߴ��Ļ�ѩ�����÷׷���������¡�" }),
			"chance"	:	10,
			"length"	:	1,
		]),
		([	"weather"	:	"��ѩ",
			"message"	:	({ "��Ǧ��û��������£�����Ʈ����ѩ����\nѩ��Խ��Խ�ܼ���Ѹ�ٳ����һ�пռ䣬���˼����������۾���",
								"��ѩ��ɣ��ڷ����Խ����գ���Х�ţ�գ�ۼ䣬ѹ��������֦��" }),
			"chance"	:	20,
			"length"	:	3,
		])
	}),
});

static int current_day_phase;
static int current_year_phase;
static int current_season;
static string current_weather;

void update_day_phase(int curPhase);
void update_year_phase(int curPhase);
void update_weather();
void init_nature_system();
int get_season();
string get_weather();

void create() {
	init_nature_system();
}

mixed *getTime(int date) {
	int curYear, curMonth, curDay, curSheChen, curKe, curDayTime;
	
	curDayTime = date % 1440;
	curKe = (date % 120) / 30;
	curSheChen = (date / 120) % 12;
	curDay = (date / 1440) % 30;
	curMonth = (date / 43200) % 12;
	curYear = (date / 518400);
	
	return ({curKe, curSheChen, curDay, curMonth, curYear, curDayTime});
}

void set_Season(int month) {
	if(month <= 3) {
		current_season = 1;
	} else if(month <= 6) {
		current_season = 2;
	} else if(month <= 9) {
		current_season = 3;
	} else {
		current_season = 4;
	}
}

// initialize nature system.
void init_nature_system() {
	mixed *local;
	int cur_time, month, day, dayTime, i, delay;

	// Get current month, day and time.
	cur_time = time();
	local = getTime(cur_time);
	month = local[3] + 1;
	day = local[2] + 1;
	dayTime = local[5];

	// Find the day phase.
	current_day_phase = -1;
	for(i=0; i < sizeof(day_phase); i++) {
		if(day_phase[i]["start_at"] > dayTime) {
			delay = cur_time - dayTime + (int)day_phase[i]["start_at"];
			EVENT_D->add_event(delay, this_object(), (: update_day_phase, i :)); 
			current_day_phase = i - 1;
			break;
		}
	}
	if(current_day_phase == -1) {
		current_day_phase = sizeof(day_phase) - 1;	
		delay = cur_time - dayTime + 1440;
		EVENT_D->add_event(delay, this_object(), (: update_day_phase, 0 :)); 
	}
	
	// Find the year phase.
	current_year_phase = -1;
	for(i=0; i<sizeof(year_phase); i++) {
		if(month < year_phase[i]["month"] || 
				(month == year_phase[i]["month"] && day < year_phase[i]["day"])) {
			delay = cur_time - dayTime + ((year_phase[i]["month"] - month) * 30 + year_phase[i]["day"] - day) * 1440;
			EVENT_D->add_event(delay, this_object(), (: update_year_phase, i :)); 
			current_year_phase = i - 1;
			break;
		}
	}
	if(current_year_phase == -1) {
		current_year_phase = sizeof(year_phase) - 1;	
		delay = cur_time - dayTime + ((12 - month) * 30 + 30 - day + 1) * 1440;
		EVENT_D->add_event(delay, this_object(), (: update_year_phase, 0 :)); 		
	}
	set_Season(month);
	update_weather();
}

void update_day_phase(int curPhase) {
	int delay, cur_time;
	
	current_day_phase = curPhase;
	cur_time = time();
	if(curPhase == sizeof(day_phase) - 1) {
		delay = cur_time - (cur_time % 1440) + 1440;
		EVENT_D->add_event(delay, this_object(), (: update_day_phase, 0 :));
	} else {
		delay = cur_time - (cur_time % 1440) + (int)day_phase[current_day_phase + 1]["start_at"];
		EVENT_D->add_event(delay, this_object(), (: update_day_phase, current_day_phase + 1 :));			
	}
	message("outdoor:vision", YEL + REV+ day_phase[current_day_phase]["event_msg"] + "\n\n"NOR, users());
}

void update_year_phase(int curPhase) {
	int delay, cur_time;
	
	current_year_phase = curPhase;
	set_Season(year_phase[current_year_phase]["month"]);
	cur_time = time();
	if(curPhase == sizeof(year_phase) - 1) {
		delay = cur_time - (cur_time % 1440) 
				+ ((12- year_phase[current_year_phase]["month"]) * 30 
				+ 31 - year_phase[current_year_phase]["day"]) * 1440;
		EVENT_D->add_event(delay, this_object(), (: update_year_phase,  0 :)); 	
	} else {
		delay = cur_time - (cur_time % 1440) 
				+ ((year_phase[current_year_phase+1]["month"] - year_phase[current_year_phase]["month"]) * 30 
				+ year_phase[current_year_phase+1]["day"] - year_phase[current_year_phase]["day"]) * 1440;
		EVENT_D->add_event(delay, this_object(), (: update_year_phase,  current_year_phase + 1 :)); 
	}
	message("vision", year_phase[current_year_phase]["event_msg"] + "\n\n", users());
}

void update_weather() {
	mixed event = weather_msg[get_season() - 1];
	int i, j, w;
	
	w = random(100);
	for(i=0; i<sizeof(event); i++) {
		if(w < event[i]["chance"]) {
			break; 
		} else {
			w -= event[i]["chance"];
		}
	}
	
	w = random(event[i]["length"] * 1440);
	j = random(sizeof(event[i]["message"]));
	current_weather = event[i]["weather"];
	message("outdoor:vision", REV + event[i]["message"][j] + "\n\n"NOR, users());
	EVENT_D->add_event(time() + w, this_object(), (: update_weather :));
	if(!undefinedp(event[i]["event"])) {
		call_other(this_object(), event[i]["event"]); 
	}
}

void add_day_event(int start_at, int length, object ob, function event_function) {
	int delay, cur_time, start_end;
	
	if(!objectp(ob)) {
		return;
	}
	start_at = (start_at % 24) * 60;
	cur_time = time();
	if(start_at > (cur_time % 1440)) {
		delay = cur_time - (cur_time % 1440) + start_at + random(length*60);
	} else {
		delay = cur_time - (cur_time % 1440) + 1440 + start_at + random(length*60);
	}
	EVENT_D->add_event(delay, ob, event_function); 
}

void add_year_event(int month, int day, int length, object ob, function event_function) {
	int delay, cur_time, start_at, ranDelay;
	
	if(!objectp(ob)) {
		return;
	}
	start_at = ((month-1) * 30 + day - 1) * 1440;
	cur_time = time();
	if(start_at > (cur_time % 518400)) {
		delay = cur_time - (cur_time % 518400) + start_at + random(length * 1440); 
	} else {
		delay = cur_time - (cur_time % 518400) + 518400 + start_at + random(length * 1440); 
	}
	EVENT_D->add_event(delay, ob, event_function); 	
	
}

void event_noon() {
	object *ob;
	int i, skill;

	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( !ob[i]->query("mana") ) continue;
		if( !(skill = ob[i]->query_skill("spells", 1) )) {
			tell_object(ob[i], "�����һ����ѣ��������һ�����������ϱ��������ˡ�\n");
			ob[i]->set("mana", 0);
			ob[i]->receive_damage("sen", 0);
		} else if( skill < 25 ) {
			tell_object(ob[i], "����ʱ�̣��������ķ�����ʼ��ʧ�ˡ�\n");
			ob[i]->set("mana", (int)ob[i]->query("mana") * skill / 25 );
		}
	}
}

void event_summer_thunder() {
	object* list;
	object me;

	list = users();
	if(!sizeof(list)) {
		return;
	}
	me = list[random(sizeof(list))];
	if(objectp(me) && objectp(environment(me)) && environment(me)->query("short") == "��������" ) {
		environment(me)->event_thunder(me);
	}

	me = load_object("/d/xiangsi/leidashi");
	if (me)
		me->event_thunder();

}

void event_summer_storm() {
	object* list;
	object me;

	list = users();
	if(!sizeof(list)) {
		return;
	}
	me = list[random(sizeof(list))];
	if(environment(me) && environment(me)->query("outdoors") && random(me->query_kar()) < 10) {
		message_vision(HIR"һ�����������$N��ͷ�ϣ�\n\n"NOR, me);
		me->receive_damage("kee", 50);
	}
}

void event_winter_wind() {
	object* list;
	object me;
	
	list = users();
	if(!sizeof(list)) {
		return;
	}
	me = list[random(sizeof(list))];
	if(environment(me) && environment(me)->query("outdoors")) {
		if(random(me->query_con()) > 20) {
			message_vision(HIG"$N����һ��������ɫ������������\n\n"NOR, me);
			me->set_temp("apply/durability", 2);
		} else {
			message_vision(HIR"$N���������Ĵ���һ����ս��\n\n"NOR, me);
			me->receive_damage("kee", 50);
		}
	}
}

string outdoor_room_description() {
	return "    " + year_phase[current_year_phase]["desc_msg"] + "��" 
			+ get_weather() + "��\n"
			+ "    " + day_phase[current_day_phase]["desc_msg"] + "��\n";
}

int get_current_day_phase() { 
	return current_day_phase; 
}

int get_current_year_phase() { 
	return current_year_phase;
}

int get_season() { 
	return current_season; 
}

string get_weather() { 
	return current_weather; 
}

int is_day_time() { 
	return ((current_day_phase > 1 && current_day_phase !=7) ? 1 : 0); 
}

string game_time() { 
	return CHINESE_D->chinese_date(time()); 
}

mapping *query_day_phase() { 
	return day_phase; 
}

mixed *get_current_time() { 
	return getTime(time());	
}

mixed get_weather_mesg() {
	return weather_msg[0][1];
}