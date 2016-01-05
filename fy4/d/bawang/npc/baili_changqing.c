inherit NPC;
#include <ansi.h>
int proceed();

void create()
{
	set_name("���ﳤ��", ({ "baili", "baili changqing"}) );
	set("nickname", HIC "�ɶ�����"NOR);
	set("gender", "����" );
	set("age", 54);
	set("per", 25);
		
	set("attitude","friendly");
	set("attitude", "peaceful");
	set("no_arrest", 1);
	
	set("combat_exp", 2800000);
	set("score", 90000);
	
	set_skill("perception",150);
	set_skill("unarmed", 170);
	set_skill("parry", 150);
 	set_skill("dodge", 150);
	set_skill("dragonstrike", 170);
	set_skill("huntunforce", 200);
	set_skill("tie-steps", 150);
	set_skill("move",	150);
		
	map_skill("unarmed", "dragonstrike");
	map_skill("force", "huntunforce");
	map_skill("dodge", "tie-steps");
	map_skill("move","tie-steps");
	map_skill("parry","dragonstrike");
	
	set("inquiry",	([
			"gui dong jing" : (: proceed :),
			"gui dongjing" :(: proceed :),
			"guidongjing":(: proceed :),
			"�鶫��":(: proceed :),
		]) );
	set("chat_chance",1);
	set("chat_msg",({
		"���ﳤ��Ե˶���������ұ��������ɱ�㣬����......\n\n���а�......��\n",	
	}));	
	set("long",
		"������ĸߴ��ΰ��˫Ŀ���ⱬ�䡣��������Զ���ĳ����ھֵ����ˡ�\n"
		);
	setup();
    carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	object me;
	::init();
	me = this_player();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1); 
	if(me && userp(me) && environment(me) == environment() && !me->is_fighting()) {
		call_out("greeting", 2, me);
	}
}

int greeting(object me)
{
	object room;
	if(!me || environment(me) != environment() || me->is_fighting()) return 1;
	if( userp(me) )
	{
		if( !REWARD_D->check_m_success(me, "�ھ��ڼ�"))
		{
			command("say ��λ" + RANK_D->query_respect(me)+"���Ϸ���Ҫ�������ϸ������������õ����Ѿ�һ��ս......\nҲ�ã���������������֤�ɡ�\n");
		} else {
			command("say ��λ" +RANK_D->query_respect(me)+"�����ｫ��һ����ս���ط���С���㻹��ȥ��ȫ�ĵط��ɡ�\n");
			message_vision("$N����һ�ӣ�һ����͵ľ��罫$n�������ͳ����������¡�\n",this_object(),me);
			room = find_object("/d/bawang/undertower2");
			if(!room) room=load_object("/d/bawang/undertower2");
			me->move(room);
			message("vision", me->name()+"�������滺������������\n", environment(me), me);
		}
	}
	return 1;
}

int proceed()
{
	object me;
	object room;
	object note;
	me = this_player();

	if (me->is_fighting()) return 1;
	command("say ��λ" + RANK_D->query_respect(me)+"�������⡰������Ȯ�족���ڼ��ǹ鶫����\n");
	command("consider");
	command("say �Ϸ�Ҳ��������º�������Σ������Һ͵��ֵܶ�������
�鶫�����ڼ�ĵ��ˡ������Ҷ���ƴ�����ܾ��ˣ���������������\n\n\n");
	REWARD_D->riddle_set(me,"�ھ��ڼ�",1);
	
	message_vision(HIR"�����ͻȻ����һ����Ц����������죬��ȥ�ɣ���\n"NOR, me);
	message_vision(HIW"һƬ���������İ������������ױȵ��ٶ���$N������
$N�Ѿ��޷���ܣ�ֻ�ñ�Ŀ����������\n"NOR, me);
	message_vision(HIR"\nֻ����$Nһ�����ȣ������ߣ���\n$nֻ����һ����ɽ��������������ػ�������������$n�������Ʊڶ�����
���ɵ���Ѫ���磬һ�������˹�ȥ��\n"NOR,this_object(),me);
	message_vision("���Ժ����У�$N������һƬ��Ҷ��������Ʈ�䣬�ƺ�����һ��������
ס��$N����������\n",me);
	room = find_object("/d/bawang/undertower2");
	if(!room) room=load_object("/d/bawang/undertower2");
	me->unconcious();
	me->move(room);
	message("vision", "������ͻȻ����һ����ȣ����أ�����һ����ֻ��"+me->name()+"������������Ʊڶ�����
�漴һ�������������ɳ�����ס��"+me->name()+"������ʹ"+me->name()+"�����建������������ߵĲݵ��ϡ�\n", environment(me), me);
	message("vision", "�����в��ϴ������أ�ž�����ľ��������ŭ�Ⱥ͵�߳����ö���ҡҡ��׹��
����㵽���㣬���ϵ��д���שʯ����ľ�ɳ����ڵײ㣬����һ������
���صľ��죬������Ȼ�������������������У�������Ӱ�ƺ������Ϸ���
�ɱ���ȥ��\n", environment(me), me);
	message("vision", "����һ�˴ӷ���������"+me->name()+"��ߣ��Ҵ�д��һ��ֽ��������"+me->name()+"���У�
�漴Ҳ׷�����϶�ȥ��\n", environment(me), me);
	note = new(__DIR__"obj/dingxi_note");
	if (note) note->move(me);
	return 1;
}
