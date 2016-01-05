// garrison.c

#include <ansi.h>

inherit NPC;
void create()
{
    set_name("���䳤", ({ "yuzu zhang", "yu zu zhang" }) );
    set("long","���ϴ��ε����䳤���Ų����˶���������һ�仰��\n");
    set("attitude", "heroism");
    set("combat_exp", 1000000);
    
    set("chat_chance", 1);
    set("chat_msg", ({
		"���䳤����������������������������Ӵ�ƺȡ���\n",
    }) );
    setup();

    carry_object("/obj/armor/cloth")->wear();
}

void destory_this()
{
	message_vision("$N���ͷ���������û������Ǿ�������ɣ�������ٽ��ҡ���\n",this_object());
	message_vision("$N��Ȼ�����ȥ�� \n",this_object());
	destruct(this_object());
	return;
}

void release_player(object player)
{
	message_vision("$N˵�������ȥ���ٺ١�����\n",this_object());
	message_vision("$N��������û�ˣ�������$n˵��������Ǯ�Ϳ��Է����ȥ���㸶�����𣿡� \n",this_object(),player);
	message_vision("$N����һ�����ƣ�������������������ƽ�50������ֱ�Ӵ����ʻ���ת��Ը��Ը�⣿
	(ACCEPT YES/NO)��  \n",this_object());
	add_action("do_accept","accept");
	call_out("destory_this",20);
}

int do_accept(string arg)
{
	object player, room;
	int amount;
	player = this_player();
	remove_call_out("destory_this");
	if (arg == "yes")
	{
		amount = player->query("deposit");
		if (amount < 500000)
		{
			message_vision("$N�����ܻ���$n������Ҳ���ˣ������������û��ô��Ǯ����ˣ�ң����Ҹɻ�ȥ�ɣ��� \n",this_object(),player);
			message_vision("$N��Ȼ�����ȥ�� \n",this_object());
			message_vision("$N�����������ƻ�������Ѻ���ˡ�\n",player);
			if (!room= find_object(AREA_JINAN"pyard"))
				room=load_object(AREA_JINAN"pyard");
			player->move(room);
			destruct(this_object());
		}else
		{
			amount = amount - 500000;
			player->set("deposit",amount);
			message_vision("$N�����ֺõ�Ц��$n˵�����Ҿ�˵��λ"+ RANK_D->query_respect(player) + "�Ǵ����ˣ������ߡ���\n",this_object(),player);
			message_vision("$N��$n������η��� \n",this_object(),player);
			player->set("vendetta/authority", 0);
			player->delete("marks/crime");
			player->move("/d/jinan/dayu");
			player->set("startroom",AREA_FY"fqkhotel");
			message_vision("$N�����˺۵ĳ����η��� \n",player);
			destruct(this_object());
		}
		return 1;
	}
	if (arg == "no")
	{
		message_vision("$N��ߵ���������ҪǮ��Ҫ���ļһ������������ŵ���ʱ���� \n",this_object(),player);
		message_vision("$N�е�����ѽ������һ��ϵ�Ժ����ȥ�ɻ\n",this_object(),player);
		message_vision("$N��Ȼ�����ȥ�� \n",this_object());
		message_vision("$N�����������ƻ�������Ѻ���ˡ�\n",player);
		if (!room= find_object(AREA_JINAN"pyard"))
			room=load_object(AREA_JINAN"pyard");
			player->move(room);
		destruct(this_object());
		return 1;
	}
	return notify_fail("��ֻ��ACCEPT YES OR NO \n");
}


