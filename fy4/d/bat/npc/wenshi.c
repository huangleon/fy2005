// wenshi.c 

#include <ansi.h>

inherit NPC;

void create()
{
    	set_name("������ʿ", ({ "wenshi" }) );
	set("gender", "����");
	set("age", 42);
	set("long",
		"��λ������ʿ����Ǳ��������ʲô��˿��ûע�����˽�����\n");
    	set("combat_exp", 650000);
	set("attitude", "friendly");

    	set("chat_chance", 2);
    	set("chat_msg", ({
        	"������ʿ��������������������֮���������ˣ�... \n",
        	"������ʿ��¶����֮ɫ�������˵�֪���������У�ȴ��֪��������У�
���ǹ���Ī�⣡\n",
    	}));
    	set("inquiry", ([
            	"��������" : "�ƺ������Һ�ǰ�����\n",
		"maze" : "�ƺ������Һ�ǰ�����\n",
     	]));
     	setup();
     	carry_object("/obj/armor/cloth")->wear();
}

