#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
  	set_name("��Ӧ�鵤",({"panacea"}));
  	set("long", "һ�����ܾ���������Ӧ�鵤����˵�����˽������״̬�����վ���\n");
  	set("desc_ext","���ã�eat panacea��");
  	set("base_value",10000);
  	set("unit","��");
  	set("base_unit","��");
  	set("base_weight",10000);
  	set("volumn",1);
	set("lore",1);
  	set_amount(1);
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_cure",({"eat" }));
}

int do_cure(string arg)
{
	object me;
	mapping buff;
	me = this_player();
	
	if (arg != "panacea")
		return 0;
		
	if (me->is_busy())
		return notify_fail("��������æ��\n");
  	message_vision(CYN"$N��æ���ҵĽ���Ӧ�鵤��������ȥ��\n"NOR,me);
	if (me->is_fighting())
	{
		if (me->query("timer/jiasi") + 1800 <= time())	// 30����һ��
		{
			me->set("timer/jiasi",time());
			tell_object(me,MAG"ҩһ�¶ǣ���ֻ���ø�����ͬ������ʹ���ɵ���\n");
			message_vision(RED"$N����ͻȻ�����Ť������֫��ʼ���ҳ鴤��\n"RED"һ˿��ɫ����Ѫ��$N�ڱ������˳���������\n"NOR"\n",me);
			me->remove_all_killer();
			me->remove_all_enemy();
			me->set("eff_kee",1);
			me->set("kee",1);
				buff =
			([
				"caster":me,
				"who":me,
				"type":"freeze",
				"att":"curse",
				"name":"����칬����Ӧ�鵤",
				"buff1":"disable_inputs",
				"buff1_c":1,
				"buff2":"is_unconcious",
				"buff2_c":1,
				"buff3":"block_msg/all",
				"buff3_c":1,
				"disable_type":NOR CYN " <���ز���>" NOR,
				"time":300,	// ��ҩ������ʱ�伫����
				"buff_msg":"$N���ˡ�\n"NOR,
				"disa_msg":CYN"\n\n$N�ڵ������������£���������������\n"NOR,
				"disa_type":1,
			]);
			ANNIE_D->buffup(buff);
			me->add_temp("block_msg/all",-1);
			tell_object(me,HIY"\n�����š�"+me->query("name")+"("+me->query("id")+")Ī����������ˡ�\n"NOR);
			tell_object(me,"\n���Ź� - \n    ��һ���ѣ��������ڹ��Źأ��ߴ�ĳ�ǽ��μˮ���ƣ�����ɭɭ��������Ŀ��\n����ţͷ�������ֳ��������س��ţ��������ֳ�����������ק�ż�����Ӱ���˽�ȥ\n��������������������¥�ϸ���һ�����ң�\n\n\n"RED"                        ���Ź�"NOR);
			tell_object(me,"\n\n    �������Եĳ����� "HIG"south"NOR" �� "HIG"east"NOR"��"HIW"\n  ���� ţͷ"NOR"(Niutou)\n"HIW"  ���� ����"NOR"(Mamian)\n");
			tell_object(me,"  ����й�(Panguan)\n\n�йٺȵ���ţͷ��������ڣ�\n\n"HIW"�й���������Ŀ����ѵ�һ����������ɨ��ɨȥ��\n\n"HIR"�����ǰһ�ڣ�����ʲ��Ҳ��֪����....\n\n"NOR);
			me->add_temp("block_msg/all",1);
		}
	}
  	add_amount(-1);
  	return 1;
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
