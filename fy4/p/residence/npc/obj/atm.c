#include <ansi.h>
inherit __DIR__"annieitem";
inherit F_BANKOWNER;

void create()
{
	set_name("�������", ({ "automatic teller machine"}) );	// �����id�б���������������ʹ�õ���id!
	set_weight(30000);
    set("richness",999999999);
	set("unit", "��");
	set("desc", "һ��������Ц�Ĳ���������������ִ�����е�ָ�
convert     �һ�Ǯ��
withdraw    ��ȡ���
deposit     ����Ǯ��
balance     ��ѯ�������
loan	��Ǯׯ��Ǯ
transfer    ֱ��ת��\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("no_split",1);
	set("item_type","n");
	set("size",1);
	set("tax",10);
	set("score_tax",1);
	set("value", 500000);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment()->is_owner(this_player()->query("id")))
	{
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
		add_action("do_loan","loan");
		add_action("do_transfer","transfer");
	}
}



/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
