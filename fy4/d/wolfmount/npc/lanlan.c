#include <ansi.h>
inherit NPC;
void create()
{       
        set_name("����", ({ "lan lan","lan" }) );
        set("long", "�������ʻ���ʢ���������ǰ��ǧ�����ġ�\n");
        set("age", 20);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("combat_exp", 1500000); 
        set("inquiry", ([
        	"С��": "��ǰȥ��������̫ү�ҳ�Ļ����ʹ�����������������ˡ�\n",
	]) );
        set("chat_chance",1);     
        set("chat_msg",({
		"�����޺޵�������ͷ¿�ӣ��ֲ�֪��������ȥ�ˡ���\n",
	}) );

        setup();
        carry_object(__DIR__"obj/blue_skirt")->wear();
}
