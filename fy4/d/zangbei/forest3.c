inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
������һƬ��ڣ�������Ҷ������������Ҳ������ҹ�����ְ�����������⡣
�ߴ�������������衣��ή���ӵİ������ֱ�϶����ɪɪ�����������Ұ���ں���
�������Ƶ������ζ�����ç������չ����������˳��ۣ���צ���ˡ�
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"forest2",
		"southeast":	__DIR__"forest4",
	]));
        set("item_desc", ([
        	"tree": "�ߴ����ľ��û��һ���Ĺ�������������ȥ��\n",
		"����": "�ߴ����ľ��û��һ���Ĺ�������������ȥ��\n",
		"��":   "�ߴ����ľ��û��һ���Ĺ�������������ȥ��\n",
		"����": "ï�ܵİ������ڵ��Ͻ�֯������ʹ�˼����������Ų�������ϸ������һ����
������������������ɫ��������һͷ���ڵ��ϣ���һͷ��������ϣ�����
�Ǹ����壨disarm����\n",
		"bush": "ï�ܵİ������ڵ��Ͻ�֯������ʹ�˼����������Ų�������ϸ������һ����
������������������ɫ��������һͷ���ڵ��ϣ���һͷ��������ϣ�����
�Ǹ����壨disarm����\n",
		"vine": "ï�ܵİ������ڵ��Ͻ�֯������ʹ�˼����������Ų�������ϸ������һ����
������������������ɫ��������һͷ���ڵ��ϣ���һͷ��������ϣ�����
�Ǹ����壨disarm����\n",
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1580);
        set("coor/y",640);
        set("coor/z",0);
		set("map","zbwest");
		set("trap",1);
		setup();
}


void 	reset(){
	::reset();
	set("trap",1);
}


void 	init()
{
        add_action("do_disarm","disarm");
        add_action("do_nothing", "");
	add_action("do_look","look");
	add_action("do_chat","chat");        
	add_action("do_emote","chat*");                
	add_action("do_quit","quit");
	add_action("do_climb","climb");
}	

int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg || (arg!="tree" && arg!="��")) 
		return notify_fail("������ʲô��\n");;
	tell_object(me,"˵�㲻�У���Ͳ��У���Ҳ���У��������С�\n");
	message_vision("$Nץ�������������˰��죬һ�����ֵ���������\n",me);
	return 1;
}

int valid_leave(object who, string dir){
	object another;
	seteuid(getuid());
	
	if(dir == "southeast"){
		if (query("trap")) {
			message_vision(BLU"$N��Ȼ���ý���һ��˵ʱ����ʱ�죬������֦��ס��$N��˫�ȡ�\n"NOR,who);
			message_vision(BLU"$Nһ�����ԴУ���ͷ���±�����������\n"NOR,who);
			who->start_busy(1000);
			who->set_temp("condition_type",HIW "<����������>" NOR);
			call_out("release_trap",60,who);
			return notify_fail("");
        	}			
	}	
	return 1;
}


int 	release_trap(object who) {
	
	if (!who->query_temp("condition_type") || who->is_ghost() || environment(who)!= this_object())
		return 1;
	message_vision(HIG"$N������ƴ�������ţ����ڡ�������
��ͨһ������֦������$N�����������ˣ�$N���ص��䵽���ϡ�\n"NOR,who);
	who->stop_busy();
	who->delete_temp("condition_type");
	return 1;
}

int 	do_disarm() {
	object *inv,*players;
	int i;
	
	if (!query("trap"))
		return notify_fail("Ȧ���Ѿ����ƻ��ˡ�\n");
	message_vision(YEL"$N�������ӣ�С������ؽ������ƿ���\n"NOR,this_player());
	set("trap",0);
	inv=all_inventory(this_object());
	players=filter_array(inv,(: userp($1) && $1->query_temp("condition_type")==HIW "<����������>" NOR :));
	if (players && sizeof(players)>0) 
	for (i=0;i<sizeof(players);i++) {
		players[i]->stop_busy();
		players[i]->delete_temp("condition_type");
		message_vision(HIG"$N����һ�ɣ����ص��䵽�˵��ϡ�\n"NOR,players[i]);			
	}
	return 1;
}


int 	do_nothing(string arg)
{
	if (this_player()->query_temp("condition_type")) {
		tell_object(this_player(),WHT"�㱻��������һ��Īչ������ֻ�но����ˣ�����\n"NOR);
		return 1;
	}
	else return 0;
}

int 	do_chat(string arg)	{
	CHANNEL_D->do_channel(this_player(), "chat", arg);
	return 1;
}

int 	do_emote(string arg)	{
	CHANNEL_D->do_channel(this_player(), "chat*", arg);
	return 1;
}

int 	do_look(string arg)		{
    	"/cmds/std/look"->main(this_player(),arg);
    	return 1;
}

int 	do_quit()	{
	if (wizardp(this_player())) {
		this_player()->stop_busy();
		this_player()->delete_temp("condition_type");
		message_vision(HIG"$N����һ�ɣ����ص��䵽�˵��ϡ�\n"NOR,this_player());			
	}
	return 1;
}