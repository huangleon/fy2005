#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("��ͯ", ({ "fish boy","boy" }) );
        set("gender", "����");
        set("age", 11);
        set("title", "��������");
    set("long","���Ž�Ѿ������ͯҥ���ڱ̺���ɳ���������ڵ���Ϸ��ˣ��\n���ֵ�ʱ�Ⱑ��һȥ������\n");
        set("chat_chance", 1);
        set("chat_msg", 
           ({
"��ͯ����ŤŤ���ں�̲����Ϸ���������Ÿ�ҥ��\n"+CYN
"          ���Ƶ��ϰ�����          �����黭���쳾
          һ������������          ������ͽ�䷲��\n"NOR,
"��ͯ���˲���ͨͨ�ı��ӣ�����������\n"+CYN
"          һ�������ǹ³�          ������˫Ϊ��ͼ
          ��������������          ������ʵ�Ӵ���\n"NOR,
            }) );
    set("combat_exp", 5000);
	set("attitude", "friendly");
	setup();
    if (!random(3)) carry_object(__DIR__"obj/goldfishtank");
	carry_object("/obj/armor/cloth")->wear();
}
