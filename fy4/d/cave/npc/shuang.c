#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("˫˫", ({ "shuang shuang","shuang" }) );
        set("gender", "Ů��");
        set("age", 19);
        set("title", "äŮ");
    	set("long","
�����ֱ�ϸ�������������Ǹ����ӣ������Ⱥ��ӻ�Ҫ��С�������۾��ܴ󣬵�
ȴ�����ɵ�ȫ�޹�ʣ����Ǹ�Ϲ�ӡ�����������֣��ǲ����ǳ�ª��Ҳû�в�
ȱ��ȴ����һ��׾�ӹ������������������ߣ�һ������Ť�������ε�������
�ߡ���������������ϧΪ������һ�е�Ů�ˣ������Ǹ�������ȫ�Ļ��ζ���
���һ��Ǹ�Ϲ�ӡ� ��\n");
    	set("combat_exp", 5000);
	set("attitude", "friendly");
	setup();
	carry_object("/obj/armor/cloth")->wear();
        this_object()->disable_player(" <���Բ���>");
        this_object()->set_temp("is_unconcious",1);
        set_temp("block_msg/all", 1);
        COMBAT_D->announce(this_object(), "unconcious");
}
