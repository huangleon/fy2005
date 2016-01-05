
#include <ansi.h>

inherit NPC;
int weapon();
void create()
{
        set_name("ĥ������", ({ "old man","man" }) );
        set("long",
"һͷ�ҷ���˥�϶�����Щȳ�ŵ�ĥ�����ˡ�����һ˫��ʮ���ȶ���ÿ��������
һ�Ѻõ�����ʱ���ܲ�����������������̾����˵��������һ������������
"YEL"����"NOR"�Ĵ�ʦ��ȴ��֪Ϊ�������˼�ҵ���������С�򣬾�˵��Ϊ��ҪѰ������
��"YEL"��ʯ��\n"NOR);

    	set("attitude", "friendly");

    	set("age",72);
   		set("agi", 50);

    	set("combat_exp", 500000);
		set_skill("unarmed",150);
		set_skill("parry",150);
		set_skill("dodge",150);
		
	set("inquiry", ([
		"weapon" : 	(: weapon :),
		"����" : 	(: weapon :),
		"bingqi" : 	(: weapon :),
		"��ʯ":	"��˵�е������ʯ�������Ƕ�ڱ����ϣ�������������������ԡ�\n",
		"����":	"��˵�е������ʯ�������Ƕ�ڱ����ϣ�������������������ԡ�\n",
		"stone":	"��˵�е������ʯ�������Ƕ�ڱ����ϣ�������������������ԡ�\n",
                "����" : 	"��������������ͷ��Ů����\n",
                "������":	"�������Ƿ��Ƴ���ļ���ʦ��\n",
                "���" : 	"���������Ĳ�ͷ�������ƻ�һ�ٰ�ʮ���������Ĵ󰸡�\n",
                "yang" : 	"���������Ĳ�ͷ�������ƻ�һ�ٰ�ʮ���������Ĵ󰸡�\n",
                "yang zheng" : 	"���������Ĳ�ͷ�������ƻ�һ�ٰ�ʮ���������Ĵ󰸡�\n",
                "���³���":	"���³����㶼��֪���������й���ô��\n",
                "di qinglin" : 	"����������С��ү����ͽ�������֡�\n",
                "������" : 	"����������С��ү����ͽ�������֡�\n",
                "���":	"��������۹�סʲô�������������������ס����֣����
�־�Ҫ��������������ס��Ľţ���Ľžͺ�������������ס����ʺ�
���Ҫ�������������ˡ� \n",
		"��һ��":	"�����񽣡���������������������\n",
		"����ү":	"����ү�������׸���ǰЩ���Ȼ����������ˡ�\n",
        ]));
    
    	set("chat_chance", 1);
    	set("chat_msg", ({
			"ĥ��������������������������֮�յ��ܵü����������𹳡���Ҳ�㲻�������ˡ�\n",
    	}) );
	setup();
        carry_object("/obj/armor/cloth")->wear();
}


void init(){
	::init();
    	add_action("do_qian", "imbue");
}

int weapon(){
	object me;
	me = this_player();
	message_vision("$N��̾һ���������������Եģ������Ե���Ʒ�ֿ����������������ԣ�������������ѽ��\n", this_object());
	return 1;
}

int imbue_event(object who, string name, string atr) {

	mapping data;
	data = ([
			"name":		name,
			"target":	who,
			"att_1":	atr,
			"att_1c":	2,
			"mark":		1,
		]);
	REWARD_D->imbue_att(data);	
	return 1;
	
}

int do_qian(string arg){
	object me, weapon, stone;
	string obj, item, prop;
	mapping data;
	
	me = this_player();
	if(!arg) {
		return notify_fail("��ҪǶʲô������\n");
	}
	if(!sscanf(arg, "%s with %s", obj, item)) {
		return notify_fail("��ʽ��������� ĳ�� ������� ĳ�\n");
	}
	weapon = present(obj, me);
	stone = present(item, me);
	if(!objectp(weapon) || !objectp(stone)){
		return notify_fail("��û�����������\n");
	}
	if(weapon->query("owner") != me->query("id") || !weapon->query("owner")) {
		return notify_fail("�㲻������Ƕ���������\n");
	}
	if(!stone->query("imbue")){
		return notify_fail("�������������������Ƕ��\n");
	}
	
/*	if(stone->query("stone_owner")!= me) {
		message_vision(YEL"$N̾����˵����ʯ�����������������ȥҲû�á�\n"NOR,this_object());
		return 1;
	}*/
		
	message_vision("$N����" + stone->name() + "��"+weapon->name()+"������á�\n", this_object());
	
	weapon->unequip();
	if(weapon->query("weapon_prop")) {
		prop="weapon_prop/";
	}
	if(stone->query("id") == "topaz") {
		if(me->query("imbue/ystone")) {
			return notify_fail("���Ѿ�����һ����Ƕ��������ˡ�\n");
		}
		if (!REWARD_D->check_m_success(me,"��¶��ʯ")){
			message_vision(YEL"$N̾����˵����ʯ�����������������ȥҲû�á�\n"NOR,this_object());
			return 1;
		}
		message_vision(HIY"\n��¶��ʯ���������Ļ�ɫ��â.... һ�����������"NOR + weapon->name()+"��\n",
				this_object());
			
		// ������⿿������û���κξ�������
		me->set("imbue/ystone", 1);
		imbue_event(me, "��¶��ʯ","kar");

	} else if(stone->query("id") == "diamond") {
		if(me->query("imbue/bstone")) {
			return notify_fail("���Ѿ�����һ����Ƕ��������ˡ�\n");
		}
		if (!REWARD_D->check_m_success(me,"�̺�����")){
			message_vision(YEL"$N̾����˵����ʯ�����������������ȥҲû�á�\n"NOR,this_object());
			return 1;
		}
		message_vision(HIC"�̺����ķ���ӨӨ����ɫ��â.... һ�����������"NOR + weapon->name()+"��\n",
				this_object());
		// �����Լ������ҪL60���ϰ�
		me->set("imbue/bstone", 1);
		imbue_event(me,"�̺�����","cps");

	} else if(stone->query("id") == "ruby"){
		if(me->query("imbue/rstone")) {
			return notify_fail("���Ѿ�����һ����Ƕ��������ˡ�\n");
		}
		if (!REWARD_D->check_m_success(me,"�����൤")){
			message_vision(YEL"$N̾����˵����ʯ�����������������ȥҲû�á�\n"NOR,this_object());
			return 1;
		}
		message_vision(HIR"�����൤�������׵ĺ��.... һ�����������"NOR + weapon->name()+"��\n",
				this_object());
		// ���ô��Ҳ���л��ɳ˲���ֵģ��ر���Healer�������������־������ְɡ�
		me->set("imbue/rstone", 1);
		imbue_event(me,"�����൤","str");

	} else if(stone->query("id") == "amethist") {
		if(me->query("imbue/pstone")) {
			return notify_fail("���Ѿ�����һ����Ƕ��������ˡ�\n");
		}
		if (!REWARD_D->check_m_success(me,"��ڤ�Ͼ�")){
			message_vision(YEL"$N̾����˵����ʯ�����������������ȥҲû�á�\n"NOR,this_object());
			return 1;
		}
		message_vision(HIM"��ڤ�Ͼ��������ĵ���ɫ��â.... һ������ϼ����"NOR + weapon->name()+"��\n",
				this_object());
		
		// ����и������ţ�Doable at any EXP RANGE
		imbue_event(me,"��ڤ�Ͼ�","agi");
		me->set("imbue/pstone", 1);

	} else if(stone->query("id") == "jade") {
		if(me->query("imbue/gstone")) {
			return notify_fail("���Ѿ�����һ����Ƕ��������ˡ�\n");
		}
		if (!REWARD_D->check_m_success(me,"�������")){
			message_vision(YEL"$N̾����˵����ʯ�����������������ȥҲû�á�\n"NOR,this_object());
			return 1;
		}
		message_vision(HIG"������䷢���ĳα̵��̹�.... һ�����������"NOR + weapon->name()+"��\n",
				this_object());
		// at least L50+ to beat 76
		me->set("imbue/gstone", 1);
		imbue_event(me,"�������","int");

	}
	destruct(stone);
	weapon->save();
	return 1;
}

int accept_object(object me, object obj)
{
	object weapon;
	mixed *inv;
	int i, j;
	string msg;
	
	if (obj->query("real_leavehook"))
	{
	 if (obj->query("hook_owner")== me)
	{ 
		msg = YEL"
ĥ������˫���չ����Թ������죬������ӭչ�������¡����������۾��⣬
������˷·��Ѿ���һ˲�仯����һ��ʯ���������������������顢
���Ļ꣬�·�����һ˲����ȫͶ��������ס��������

ĥ�����˻�����˵���˹��ǲ���֮������Ǹ��������ε��ˣ������ʹ�
�������������һ��¯�����������˾���˶�����\n"NOR;

		if (!obj->query("blood"))
		{
			msg += HIR"
�����ô˹������ܳư����£�һ����Ҳ��Ȼ������ʹ���ң�\n\n"NOR;
			
		} else
		{
			msg += WHT"
����������������Ѿ��������ˣ�����������Ѫ�����ˡ���Ϊ��һ������
Ӧ�����������ˣ�ȴ��������������Ȼû��ɱ�۴�ʦ���۴�ʦȴҲ������
�����ģ����Ѿ���������ľ����������˳���Թ�����޵ı�ল���֮����
ֻ�������Լ���Ѫ���л�����ˡ�

ĥ�����˱����۾�����̾Ϣ���ⶼ�����⣬�����ȻҪ��ȫ�㣬���Ѿ���
�԰����ˡ���ȥ�ɣ�������Ҫȥ��ʲô��������Ҫȥ�Ը�ʲô�ˣ�������
����ʧ�ܵġ�		\n"NOR;
			
		}
		message_vision(msg, me);
		return 0;
	}else
	{
		message_vision("ĥ������˵����һ��������ֻ��ϧ��������\n", me);
		return 0;	
	}
		
	}	
	
	if (obj->query("fake_leavehook"))
	{
		if (obj->query("equipped"))
			obj->unequip();
		obj->set("weapon_prop",0);
		obj->set("name",MAG"�ϵ������"NOR);
		obj->set("value",0);
		obj->set("long","һ�����ι�״�ı���,�����Ѿ��ϵ��ˡ�\n");
        	message_vision(YEL "
ĥ������С��������ḧ����𹳣����˰��Σ����������˵�������ǲ�Ҫ����
�˼�ĺá�˵�գ�ĥ�����˵�ָһ������𹳾���������һ����Ϊ���ء�\n"NOR,me);
		obj->set("fake_leavehook",0);
		message_vision("ĥ�����˽�"MAG"�ϵ������"NOR"�ݻ���$N��\n"NOR,me);		
		return notify_fail("");
	}	
	
	inv = all_inventory(me);
	j = 0;
	if(obj->query("imbue")) {
		message_vision(YEL"\n$N��ϸ���˿�$n���е�"NOR+obj->name()+YEL"��ͷ�������ã��ã��˵����\n�����������󡣡�\n"NOR,
				this_object(), me);
		
		for(i=0; i<sizeof(inv); i++){
			if(inv[i]->query("owner") == me->query("id") && inv[i]->query("weapon_prop")) {
				weapon = inv[i];
				j++;
			}
		}
		if(!weapon) {
			message_vision(YEL"\n$N��̧ͷ���˿�$n��������ʯ���������䣬��λ" + RANK_D->query_respect(me) + "����ȥ�����\n�����ı��аɡ���\n"NOR,
					this_object(), me);
			return 0;
		}
		message_vision(YEL"$N��̧ͷ���˿�$n������������Ե�����Ը�Ұ��������Ƕ�������ϣ���\n"NOR,
				this_object(), me);
		tell_object(me,WHT"
��ʽ��imbue ĳ�� with "+obj->query("id")+"
����ĳ�����Ϊ�����������������Խ�ֱ�����ӵ�������϶����������ϡ�
Ҳ����˵���Ժ�ʹ���κ��������ܵõ����档\n"NOR);
	
	}
	return 0;
}
