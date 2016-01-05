#include <ansi.h>
inherit NPC;

void create()
{
	set_name("С��", ({"xiao ma","ma"}) );
	set("title" , "��ŭ��");
	set("gender", "����" );
	set("age", 22);
	set("per", 30);
	set("no_arrest",1);
	set("no_heal",1);
	set("free_hit",1);
	
	set("str",60);
	set("long","
һ����ǿ��������ȫ�������������Ե�С����˶������з�ŭ��С��
���������˿ڣ����ƺ����԰��������������壩һ�¡�\n"
	);
		
	set("combat_exp", 5000000);
	set("score", 30000);
	set("chat_chance",1);
	set("chat_msg",({
		"С���ս���ȭͷ����ŭ�Ļ���������ȼ�ա�\n",
		"��С�գ�С�գ���С����Ϫˮ������ǰ����������ѪȾ�����峺�羵��Ϫˮ��\n",
	}) );
	
	    set("inquiry", ([
        
        	"С��" : "С�ա�С�ա���̫��ʹ��ץȥ�ˣ�����",
        	"��Ƥ" : "��Ƥ���ҵ�"WHT"����"NOR"����̫��ʹ��ץȥ�ˣ�",
        	"̫��ʹ��" : "С�պ���Ƥ����̫��ʹ��ץȥ�ˣ�����",	
        	"����":		"���������գ����ߣ�whisper����Ƥ�����ҵ����ѣ���Ҳ�����㡣\n",	
        
        ]) );
	
	set_skill("move", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("unarmed",200);
	set_skill("tigerstrike",300);
	set_skill("xueyeqianzong",200);
	
	map_skill("unarmed","tigerstrike");
	map_skill("dodge","xueyeqianzong");
	map_skill("move","xueyeqianzong");
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		add_action("do_cure", "cure");
		add_action("do_answer","answer");
		add_action("do_accept","accept");
	}
}

int do_cure(string arg)
{
	object me;
	me = this_player();
	if( arg != "xiao ma" )
		return notify_fail("��ҪΪ˭���ƣ�\n");
	else if( this_object()->query("xiaoma_cured") )
		return notify_fail("С��˵�������鷳�ˣ��ҵ������Ѿ������ˣ�\n");
	else
	{
		if (me->query("timer/cure_xiaoma") + 10800 > time())
		{
			message_vision(CYN"С��˵������ô��ô��ͻ����ˣ��ٵȵ����԰ɡ������������Ϊ��Сʱ��\n"NOR, me);
			return 1;
		}
		
		if ( me->query("force") < 1000)
		{
			return notify_fail("�����������������������������ƣ�\n");
		}
		else
		{
			write(HIW "��ȫ����ɣ�������ΪС���˹����ˡ�\n"NOR);
			message_vision(HIW"С����ʹ���Ť�����������ƽ����������������һʱ˵����������\n"NOR , me);
			me->add("force",-1000);
			this_object()->set("xiaoma_cured",1);
			me->start_busy(5);
			call_out("ask_help", 5, me);
			return 1;
		}
	}
	return 1;
}

void ask_help(object me)
{
	object obj;
//	if ( me->query("����B/��ɽ_�ƺ�")> 0 && me->query("����B/��ɽ_�ƺ�")%2 == 0)
	if (REWARD_D->check_m_success( me, "��ɽ����"))
	{
		message_vision(CYN"С���˿���˵��лл��ɱ����̫��ʹ�ߡ�\n"NOR, me);
		return;
	}
	
	if (me->query("timer/cure_xiaoma") + 10800 > time())
	{
		message_vision(CYN"С��˵������ô��ô��ͻ����ˣ��ٵȵ����԰ɡ������������Ϊ��Сʱ��\n"NOR, me);
		return;
	}
	
	me->set("timer/cure_xiaoma", time());
	if (random(2))
	{
		message_vision(HIY"С��������۾�ͻȻ������������һ����ֵ�������$N��\n"NOR, me);
		message_vision(HIY"С��ȭ˵������λ"+RANK_D->query_respect(me)+"����֪�Ƿ������Ҿȳ�С�գ���Answer Yes��No��\n"NOR, me);
		me->set_temp("marks/wolf_xiaoma_asking",1);
	}
	else
	{
		message_vision(HIY"һ�����С��������۾�ͻȻ�����������м��Ŀ���$N��\n"NOR, me);
		message_vision(HIY"С����$Nһ��ȭ���������ҵ����Ʋ��޴󰭣���֪�ɷ����鷳��λӢ�ۣ�\n���Ҿȳ���Ƥ��С�գ�������Accept Yes��No��\n"NOR, me);
		me->set_temp("marks/wolf_xiaoma_questing",1);
		return;
	}
}

void reset(){
	set("xiaoma_cured",0);			// Not really fool-proof, but might be ok :D
}



int return_home(){				
	object room;
	object wen;
	if (is_busy() || is_fighting() 
		|| query_temp("scene_start")) {
			call_out("return_home",60);
	} else {
		room = find_object("/d/wolfmount/brook3");
		if (!room) room = load_object("/d/wolfmount/brook3");
		wen = present("sun legate");
		if (wen) {
			wen->set("chat_chance_combat", 40);
			wen->set("force_factor",120);
			wen->set("combat_exp", 10000000);
		}	
		set("xiaoma_cured",0);
		set("free_hit",1);
		set("chat_chance",1);
		ccommand("sigh");
		message_vision("$N����ת���뿪�ˡ�\n",this_object());
		move(room);
	}
	
	return 1;
}

// This is called by sun legate when he dies... 5 mins nothing happesn --> xiao ma left			

int delete_mark(){
	delete_temp("scene_start");
}

int delete_scene(){
	call_out("delete_mark",120);
	return 1;
}	

int do_answer(string arg)
{
	object me, obj;
	object room;

	obj = this_object();
	me =this_player();
	if(!me->query_temp("marks/wolf_xiaoma_asking")) return 0;

	if( arg == "yes" || arg == "YES" )
	{
		me->delete_temp("marks/wolf_xiaoma_asking");
		message_vision("$N�ս�ȭͷ����С�ձ�̫��ʹ�ߵ�ҩ����ƣ����Ǿ͵�̫�����Ļ�����\n̫��ʹ�߾�һ��ս�������ټ���\n", obj);
		me->set_temp("marks/wolf_xiaoma_good", 1);
		REWARD_D->riddle_set( me, "��ɽ����",1);
//		me->set("marks/wolf_xiaoma_good", 1);
		message_vision("$Nת����Զ���ĺ�����ȥ......\n", obj);
		obj->set("chat_chance",0);
		room = find_object("/d/wolfmount/flowerboat");
		if(!objectp(room)) room = load_object("/d/wolfmount/flowerboat");
		obj->move(room);
		call_out("return_home",300);
		return 1;
	}
	else if ( arg == "no" || arg == "NO" )
	{
		message_vision("$N��ɫ��Ȼ������"+me->name()+"Ҳ�ﲻ���ң�\n", obj);
		me->delete_temp("marks/wolf_xiaoma_asking");
		return 1;
	}
	else
	{
		tell_object(me, name()+"�����Ҳ������������˼����\n");
		return 1;
	}
}

int do_accept(string arg)
{
	object me, obj;
	obj = this_object();
	me =this_player();
	if(!me->query_temp("marks/wolf_xiaoma_questing")) return 0;

	if( arg == "yes" || arg == "YES" )
	{
		message_vision("$N����Ц������л��λӢ�ۣ�\n", obj);
		me->delete_temp("marks/wolf_xiaoma_questing");
		message_vision("
$N��ɫ���ص���С�ձ�̫��ʹ�ߵ�ҩ�������ƣ�ֻ��ɱ��̫��ʹ�߲Ż������ƣ�
��Ƥ���ҵ����ѣ���̫��ʹ��ץȥ�ˣ�����������������ĸ������ҵ����֣��ٸ���
�������ҵ����ѣ����ͻ���㣡\n", obj);
		me->set_temp("marks/wolf_xiaoma_normal", 1);
		REWARD_D->riddle_set( me, "��ɽ����",1);
//		me->set("marks/wolf_xiaoma_normal", 1);
		obj->set("chat_chance",0);
		return 1;
	}
	else if ( arg == "no" || arg == "NO" )
	{
		message_vision("$N��̾һ�������˲������Լ�������ƴ��һ����\n", obj);
		message_vision("$Nת����ȥ���µ�����Ӱ������Զ......\n", obj);
		me->delete_temp("marks/wolf_xiaoma_questing");
		destruct(obj);
		message_vision("$Nʧ�����ǣ������ѵ���Ϊ�Լ���ų����Ϊ�е���ֺ�ڣ�\n",me);
		return 1;
	}
	else
	{
		tell_object(me, name()+"�����Ҳ������������˼����\n");
		return 1;
	}
}

void die()
{
	object wen, xiaolin;
	
	wen = present("sun legate");
	if (wen) {
		message_vision(HIR"$N��Ц������С�����ˣ���Ҳ������ų�ȥ��\n"NOR, wen);
		wen->set("chat_chance_combat", 40);
		wen->set("force_factor",120);
		wen->set("combat_exp", 10000000);
	}	
	
	if (xiaolin = present("xiao lin",environment(this_object())))
	{
		xiaolin->set("xiaoma_died",1);
	//	this_player()->set("marks/wolf_xiaoma_normal", 1);
	//	this_player()->delete("marks/wolf_xiaoma_good", 1);
	}
	::die();
}
