#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("������", ({ "jade seller", "seller" }) );
        set("gender", "����" );
        set("age", 49);
		set("title", "�����鱦");
        set("long", "����һλ�ʷ����ֵĵ��ƹ񣬿ɱ�С�������������鱦���Ƿ��Ƴ�������ֺ��ˣ�
���������۹�Ҳ�ǳ����׼���������һ����֪��\n");
        set("combat_exp", 1200000);
        set("reward_npc", 1);
        set("difficulty", 2);
		set("str", 60);
		
		set("inquiry", ([
        	"�Ŷ���":	"�Ŷ������Ŷ�����ԭ����Ӣ�����������Ǹ�������̽�������ˡ�\n",
    	]) );
		
		set("force_factor",60);
        set("attitude", "friendly");
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set("vendor_goods", ([
                __DIR__"obj/jade1":7,
                __DIR__"obj/jade2":7,
                __DIR__"obj/jade3":7,
                __DIR__"obj/jade4":7,
        ]) );

        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( " ���ƹ�Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�������� \n");
                        break;
                case 1:
                        say( " ���ƹ�Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�����Ǽ���֮���һ��ɡ� \n");
                        break;
		}
}

int accept_object( object who, object item){
		
		if (item->query("name") == HIM"�Ͼ���ʯ"NOR && item->query("jile")==1){
			if (REWARD_D->riddle_check(who,"�Ͼ�֮��")==2 
				|| REWARD_D->riddle_check(who,"�Ͼ�֮��/������")) {
				command("shake");
				command("say �㻹�����Ҹ��˰ɡ�");
				return 0;
			}
			
			message_vision(CYN"$N����"+item->query("name")+NOR+CYN"���˼��£����ó�����Ƭ����Ƭ�̣�üͷ������\n"NOR, this_object());
			ccommand("say �����������Σ�����Ҳ�£�����Ҳ�࣬������Ѱ������");
			ccommand("shake");
			REWARD_D->riddle_set(who,"�Ͼ�֮��/������",1);
			
			if (sizeof(who->query("riddle/�Ͼ�֮��"))==4) {
				tell_object(who, CYN"\n"+name()+CYN"˵��ֻ��һ���˻�֪����鱦ʯ���������������ֽйŶ�����
��˵������������͸������ϵ��ڹ�Ĺ���ת����ڵ��׵�����ת�ı��
û������֪�������ģ���һ��֪���ⱦʯ�ĵ�ϸ��\n");
				REWARD_D->riddle_set(who,"�Ͼ�֮��",2);
			}
			
			return 0;
		}
			
		if (item->query("thief_obj")){
			command("say С�겻����������֮�");
			return 0;
		}
				
}

int do_sell(string arg)
{
	object ob;
	int value;
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ����ʲ����Ʒ��\n");
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɣ���������Ʒ��\n");
	if( ob->query("money_id") )	return notify_fail("��Ҫ����Ǯ����\n");
	value = ob->query("value");
        if( !(value/10) ) return notify_fail("������������ֵ�ܶ�Ǯ��\n");
	if (!ob->query("thief_obj"))
	{
		return notify_fail("���ƹ�ҡͷ�������겻��������Ʒ��\n");
	}
	message_vision("$N�����ϵ�" + ob->query("name") + "͵͵�������ƹ�....\n",this_player());
	command("whisper "+this_player()->query("id")+" �ֽ���̫���ۣ�Ǯ��ת�����Ϲ����е����ϡ�\n");
	command("snicker");
	this_player()->add("deposit",value/10);
	destruct(ob);
	this_player()->start_busy(1);
	return 1;
}