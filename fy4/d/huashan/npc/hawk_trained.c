#include <ansi.h>

inherit NPC;

string player_env(string name, object me);
string *tour_room = ({  "view/d/huashan/fupi",
						"view/d/huashan/lianhua",
						"��ӥ�򶫷�ȥ��\n",
						"view/d/huashan/shanlu2",
						"view/d/huashan/lianhua",
						"��ӥ���Ϸ�ȥ��\n",
						"view/d/huashan/zhenyue",
						"view/d/huashan/lianhua",
						"��ӥ������ȥ��\n",
						"view/d/huashan/sheshen",
						"��ӥ���������ʯͷ������������׹�䣬����ɽ��ʱ����ͻȻ����������\n",
						"view/d/chenxiang/chenxiang3",
						"view/d/chenxiang/cx2",
						"��ӥ������ȥ��Խ��ԽԶ��\n",
						"view/d/chenxiang/cxcenter",
						"view/d/chenxiang/cxs3",
						"��ӥ������ȥ��Խ��ԽԶ��\n",
						"view/d/wolfmount/bigstage",
						"view/d/guanwai/shudao2",
						"view/d/guanwai/shudao2",
						"view/d/guanwai/shudao1",
						"��ӥ������ȥ��Խ��ԽԶ��\n",
						"view/d/guanwai/hutiao",
						"view/d/guanwai/yuema",
						"view/d/guanwai/yuema",
						"��ӥʱ��ʱ�ͣ����Ž���������\n",
						"view/d/guanwai/river",
						"��ӥ�ƺ���һ˫���ε�����ס����Ȼ����һ����\n",
						"view/d/guanwai/river",
						"��ӥ�Ĵ��ų�����������Ϸɸ��˼��ߡ�\n",
						"view/d/guanwai/river",
					});

void create()
{
    	set_name(HIC"��ӥ"NOR, ({ "hawk" }) );
    	set("race", "����");
    	set("age", 1);
    	set("gender", "����");
    	set("long","
һֻ������צ�Ĳ�ӥ����һ˫�����������۾��������㿴�����ް������
֮�⣬�������ѱ��֮������������ѵ������train����Ȼ������������
�۲���Χ�ĵ��Σ�spy��\n");
    	
    	set("attitude","peaceful");
    	set("weight", 3000);
		set("agi", 40);
		set("per",30);
		
		set("resistance/kee",100);
		set("resistance/gin",100);
		set("resistance/sen",100);
		
		set("no_drop",1);
		set("combat_exp", 70000);
  
		setup();
}


void init() 
{
	::init();
	if (userp(environment()))
		add_action("do_train","train");
		add_action("do_spy","spy");
		add_action("do_drop","drop");
}

int do_drop(string arg)
{
	object me,hawk;
	hawk = this_object();
	me = this_player();
	
	if (arg != "hawk" && arg !="��ӥ" && arg!="trained hawk"
		&& arg!= "��ӥ")
	{
		return 0;
	}
	
	message_vision("��ӥ��������ڿ���������Ȧ��ת˲��ȥ��\n",me);
	destruct(hawk);
	return 1;
}

int do_train(string arg)
{
	object me,hawk;
	hawk = this_object();
	me = this_player();

	if (!arg)
		return notify_fail("��Ҫѵ��ʲô��\n");
		
	if (arg != "hawk" && arg != "��ӥ")
	{
		return notify_fail("�㲻��ѵ�����������\n");
	}
	
	if (hawk->query("marks/trained"))
		return notify_fail("��ӥ�Ѿ���ѱ���ˡ�\n");
			
	if (me->query_skill("animal-training",1) < 200)
	{
		message_vision("
$N��ʼѵ��$n��
$N�⿪$n���ϵ�������
$n�������������˼�Ȧ����ʧ����Ӱ���١�\n\n",me,hawk);
		tell_object(me, "�������ѱ�����ȼ���̫���200����\n");
		return 1;
	}
	message_vision("\n$N���ĵ�ѵ��$n,$n��$N���ͷ���ƺ�������$N�Ļ���
$N�⿪$n���ϵ�������$n�������������˼�Ȧ��������$N�ļ��ϡ�\n\n",me,hawk);

	set("marks/trained",1);
	set_name(HIC"��ӥ"NOR, ({ "hawk" }) );
    	set("long","һֻ��������ӥ�������԰�����죨SPY�������");
	add_action("do_spy","spy");
	return 1;
}


int do_spy()
{
	object hawk,me,target;
	hawk = this_object();
	me = this_player();
	
	if (!hawk->query("marks/trained"))
		return notify_fail("��ӥ��δ��ѱ�������˾ͷ����ˡ�\n");

	if (!environment(me)->query("release_hawk"))
		return notify_fail("��ӥ�ձ�ѱ��������ǵ�����Ϥ�Ļ�����ȥ�ŷɡ�\n");
	
	if (environment(me)->query("release_hawk")==2)
		return notify_fail("�����͵����ӥ���ص���������������Ҳ̫����Щ�ɡ�\n");
			
	hawk->move(VOID_OB);		
	message_vision(CYN"$N�⿪��ӥ���ϵ���������ӥ���������з�ȥ������
	
	
ɽ�ȼ�������ƣ�

��ӥʱ�����ٵ�б�ų������ȥ��

ʱ����һ����������������ƽչ�ſ����������ڿ��а��裬

	\n\n"NOR, me);
	
	call_out("do_tour",1, me, 0);
	return 1;
}



void do_tour(object me, int count)
{
	object ob;
	ob=this_object();
	if (!me)
		return;
	
	if (tour_room[count][0..3] == "view")
		tell_object(me, player_env(tour_room[count][4..sizeof(tour_room[count])-1],me)+"\n");
	else
		tell_object(me, CYN"\n"+tour_room[count]+"\n"NOR);
	
	if(++count==sizeof(tour_room))
	{
		message_vision(CYN"��ӥ����Ƭ�̣�����һ������������������׹�£�
		
		
		 ��������������\n\n"NOR,me);	
		
		REWARD_D->riddle_done(me,"ѱӥ��ɽ", 50, 1);
		REWARD_D->riddle_set( me, "����ŭ��", 1);
		
		destruct(this_object());
		return;
	}
	else call_out("do_tour",2,me,count);
	return ;
}


string player_env(string room_name, object me) {
	int i;
	object *inv,env;
	mapping exits;
	string roomdesc, str, *dirs;
	
	if (!(env = find_object(room_name)))
		env = load_object(room_name);
	
	if (!env)	{
		tell_object(me, " BUG, report to wizard please\n");
		return "";
	}
	
	str = "";
	
	str += sprintf("%s \n",env->query("short"));
	
	// room descriptions.
	str += sprintf( "%s \n%s",
			env->query("long"),

	// exits.
			env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	// all things in the room.
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]->query("no_shown") ) {
			continue;
		}
		str += "  " + inv[i]->short() + "\n";
	}
	
	return str;
}

