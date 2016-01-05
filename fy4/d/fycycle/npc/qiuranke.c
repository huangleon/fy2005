inherit NPC;
#include <ansi.h>
int regive_book();
void create()
{
        set_name("��״�", ({ "qiuran han","han" }) );
        set("gender", "����" );
        set("long", "
һ�����ְ����������쳣����״󺺣���һ�״ֲ��ް����¿��϶����˲�����
����ȥ��Щ���ǣ�������Ͷ��֮�䲻�Խ���¶������Ӣ�۵����ţ�\n");

        set("class", "shaolin" );

        set("age", 51);
        set("no_arrest", 1);       
        set("combat_exp", 20000000);
        set("attitude", "friendly");
        set("toughness", 500);
        
        set_temp("apply/attack", 300);
        set_temp("apply/damage", 200);
        
        
        set("chat_chance", 2);
        set("chat_msg", ({
    		"��״�����һ���ķ�Ҿ������˵�������º������ϡ�·����أ�һ��������
����Ϊ����ֻΪСŮ���Ѽ��ǣ���δ����żң���˶����������ס�\n",
    		"��״�˵�����˷糾�����̫���ˣ���\n",
                }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
                (: perform_action, "dodge.luoyeqiufeng" :),
        }) );
		set("inquiry", ([
                "���˷糾��" : (: regive_book :),
                "��ʧ�糾��" : (: regive_book :),
                "�糾��" : (: regive_book :),
                "lost fengchen book" : (: regive_book :),
        ]));
                
        
        set_skill("yijinjing", 200);
        set_skill("fall-steps", 200);
        set_skill("force", 300);
        set_skill("unarmed", 300);
        set_skill("iron-cloth", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("move", 300);
        set_skill("luoriquan", 300);
        
        map_skill("unarmed","luoriquan");
        map_skill("force","yijinjing");
		map_skill("iron-cloth","yijinjing");
      	map_skill("dodge","fall-steps");
	
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_fight(object me)
{
        command("say ���༼��δ����������λ�������֣�\n");
        return 0;
}

int regive_book()
{
	object item,me;
	int copies;
	me = this_player();
	if (me->query("m_success/Ϸ�糾")&& me->query("marks/�糾��"))
	{
		copies = me->query("m_success/Ϸ�糾");
		if (copies > 3)
		{
			message_vision("$N��$nŭ�������������Ĵε��������㣬��Ȼ�㲻֪��ϧ���ֺα����ʡ�\n",this_object(),me);
			return 1;
		}
		me->set("m_success/Ϸ�糾",copies+1);
		item = new(BOOKS"f-"+ me->query("marks/�糾��"));
		if (item->move(me))		
			message_vision("$N�ݸ�$nһ����������������Ѫ�������ú��ղأ������ٶ�!\n",this_object(),me);
		else 
		{
			message_vision("$N���������Ϸ���̫�࣬�˷���һ�λ��ᰡ!\n",this_object(),me);	
			destruct(item);
		}
	}else
	{
		message_vision("$N����$n��Ц��������Ҫ�Գ�Ϊ��������ƽ�����թ֮ͽ����ô�ĵ���������ƭ���ҡ�\n",this_object(),me);
	}
	return 1;

}

void zhaoqin(object me){
	object hong, mask;
	string gender;
	
	mask = present("skinmask", me);
	if (objectp(mask) && mask->query("equipped")) 
		gender = mask->query("fakegender");
		
	if(me->query("gender") != "����" && gender != "����"  ){
		message_vision("$N��Ц�������������λŮ�����ⰳ��СŮ��л�ˡ�\n", this_object());
	} else if (me->query("age") >= 30){
		message_vision("$N΢ŭ��������һ����ͣ��ѵ�Ҫ��Ů���ػ��ô����<30�꣩\n", this_object());
	} else if (F_LEVEL->get_level(me->query("combat_exp")) < 14){
		message_vision("$N���ֵ���ˡ��ֱ�ԣ����²�ѧδ����ȭ�����ۣ�������ذɣ���14����\n", this_object());
	} else if ( REWARD_D->check_m_success(me,"Ϸ�糾")){
		message_vision("$N���������˹�֪�㣬��������\n", this_object());
	} else {
		
		hong = present("redcloth girl", environment(this_object()));
		message_vision("$N�����ۺ��룬����Ц�����ã�����СŮ����¹����аɣ�\n", this_object());
		me->set_temp("marks/fight_hongfunv", 1);
	}
	return;
}

void lose_fight(object obj){
	object red, item;
	int i;
	string *book = ({"iron-cloth",
			"spells",
			"magic",
			"move",
			"unarmed",
			"foreknowledge"
			});
	int n = random(6);
	
	red = present("redcloth girl", environment(this_object()));
	message_vision("$N������Ц�����ã��ã���ϲ����ң��������ѣ��׺�����������Ӣ�۱�����\n", this_object());
	message_vision("$NҲˬ�ʵ�Ц������磬��ɶ����ˣ�������ϣ�\n", red);
	message_vision("$N���˵�ͷ��\n", this_object());	 
	message_vision(CYN"\n$N�ͳ�һ�����֣����Ȼ�ؽ�����$n��\n"NOR, this_object(),obj);
	message_vision("\n$N�������죬̾�����Թ����ƣ����²�ɣ��������׿�Զ��������ʮ�꣬\n", this_object());
	message_vision("�������쳾Ҳ��������Ӣ���ǵ������ˡ�Ҳ�գ���һ����������������������������\n", this_object());
	message_vision("��������λ����Ӣ�ۣ�\n", this_object());   
	message_vision("$N�Ϲ��Ͼ�����糾��\n", obj); 
	
	REWARD_D->riddle_done( obj, "Ϸ�糾", 50, 1);
	
	item = new(BOOKS"f-"+ book[n]);
	item->move(obj);
	obj->set("marks/�糾��",book[n]);
	message_vision(HIG"\n$N����Ц�������ã���һ����Ϸ�쳾���������������߰գ�\n"NOR, this_object()); 
	message_vision(HIG"$N����Я�����Ů��֮�֣�ƮȻ��ȥ��\n"NOR, this_object());
	environment(this_object())->remove_flag();
//	-- DO NOT destroy object in lose_enemy(), it will create bugs in pfms which point to 
//		target after win-lose check !!!!
//	destruct(red);				
//	destruct(this_object()); 
	red ->set("leaving",1);
	red ->move(VOID_OB);
	this_object()->move(VOID_OB);
	call_out("leaving",2, red, this_object());
	
}

void win_fight(object obj){
	message_vision("$N������$n�ļ�򣬹�����Ц��������η��ǰ;�����������ٱ����٣�\n", this_object(), obj); 
	obj->set("marks/Ϸ�糾", 1);
	return;
}


void leaving (object red, object qiuranke){
	if (red) destruct(red);
	if (qiuranke) destruct(qiuranke);
	return;
}